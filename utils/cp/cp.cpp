/* practice code */
#include <string>
#include <vector>
using namespace std;

#include <errno.h>
#include <fcntl.h>
#include <getopt.h>
#include <libgen.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

#define ERROR_BUFF_SIZE (16 * 1024)

/**** Exceptions ****/
class MessageOnlyException : public exception {
	public:
		MessageOnlyException(const char *message) {
			m_message = string(message);
		}
		const char* what() const _GLIBCXX_USE_NOEXCEPT override {
			return m_message.c_str();
		}
	private:
		string m_message;
};
/**** Exceptions ****/

/**** CopyJob ****/
const static struct option longOptions[] = {
	{"help",				false,  NULL, 'h'},
	{"link",				false,  NULL, 'l'},
	{"symbolic-link",		false,  NULL, 's'},
	{0,						0,		NULL,  0 }
};

class CopyJob {
	public:
		CopyJob(int argc, char *argv[]);

		bool ShowHelp;
		bool CreateHardLink;
		bool CreateSymbolicLink;
		string Destination;
		string Source;
};

CopyJob::CopyJob(int argc, char *argv[]) {
	ShowHelp = CreateHardLink = CreateSymbolicLink = false;
	Destination = string("");
	Source = string("");

	char errorStrBuff[ERROR_BUFF_SIZE];

	optind = 1;
	int opt;
	int fileCnt = 0;

	while (-1 != (opt = getopt_long(argc, argv, "-hls", longOptions, NULL))) {
		switch (opt) {
			case 'h':
				ShowHelp = true;
				break;
			case 'l':
				CreateHardLink = true;
				break;
			case 's':
				CreateSymbolicLink = true;
				break;
			case 1:
				if (fileCnt == 0) {
					++fileCnt;
					Source += optarg;
				} else if (fileCnt == 1) {
					++fileCnt;
					Destination += optarg;
				}
				else {
					throw MessageOnlyException("unexpected parameter for file");
				}
				break;
			case '?':
			default:
				snprintf(errorStrBuff, ERROR_BUFF_SIZE, "unexpected parameter: %c", (char)optopt);
				throw MessageOnlyException(errorStrBuff);
				break;
		}
	}

	if (CreateHardLink && CreateSymbolicLink) {
		throw MessageOnlyException(
				"can't create hard linx and softlink at the same time");
	} else if (Source.length() <= 0 || Destination.length() <= 0) {
		throw MessageOnlyException(
				"source or destination is not set");
	}
};
/**** CopyJob ****/

class IFile {
	public:
		IFile(const char *path) {
			if (path == NULL) {
				throw new MessageOnlyException("path is null");
			}

			size_t len = strlen(path);
			m_path = new char[len + 1];
			strncpy(m_path, path, len + 1);
			char *tmp = new char[len + 1];
			strncpy(tmp, path, len + 1);
			char *base = basename(tmp);
			len = strlen(base);
			m_filename = new char[len + 1];
			strncpy(m_filename, base, len + 1);
			base = NULL;
			delete tmp;
			tmp = NULL;
		}

		const char* getFileName() const {
			return m_filename;
		}

		const char* getPath() const {
			return m_path;
		}

		virtual bool isDirectory() const = 0;

		virtual ~IFile() {
			if (m_path != NULL) {
				delete m_path;
				m_path = NULL;
			}
			if (m_filename != NULL) {
				delete m_filename;
				m_filename = NULL;
			}
		}
	protected:
		char *m_path;
		char *m_filename;
};

class File : public IFile {
	public:
		File(const char *path, blksize_t blksize, mode_t mode) : IFile(path) {
			m_blksize = blksize;
			if (blksize == 0) {
				m_exist = false;
			} else {
				m_exist = true;
			}
			m_mode = mode;
		}
		bool isDirectory() const override {
			return false;
		}
		bool exist() const {
			return m_exist;
		}
		size_t blockSize() const {
			return m_blksize;
		}
		mode_t mode() const {
			return m_mode;
		}
	protected:
		size_t m_blksize;
		bool m_exist;
		mode_t m_mode;
};

class Directory : public IFile {
	public:
		Directory(const char *path) : IFile(path) {}
		bool isDirectory() const override {
			return true;
		}
};

class FileFactory {
	public:
		static IFile* getFile(const char *path) {
			char errorStrBuff[ERROR_BUFF_SIZE];
			struct stat buff;
			if (0 != stat(path, &buff)) {
				if (errno == ENOENT) {
					return new File(path, 0, 0);
				}
				snprintf(errorStrBuff, ERROR_BUFF_SIZE,
						"Error opening file [%s]: %s", path, strerror(errno));
				throw new MessageOnlyException(errorStrBuff);
			}

			if (S_ISDIR(buff.st_mode)) {
				return new Directory(path);
			} else {
				return new File(path, buff.st_blksize, buff.st_mode);
			}
		}
};

void PrintHelp()
{
	printf("Help is coming\n");
}

int main(int argc, char *argv[]) {
	CopyJob job = CopyJob(argc, argv);

	if (job.ShowHelp) {
		PrintHelp();
		return 0;
	}

	IFile* psrc = FileFactory::getFile(job.Source.c_str());
	if (psrc->isDirectory()) {
		throw new MessageOnlyException("Source can't be a directory");
	}

	string destination = string();
	IFile* pdst = FileFactory::getFile(job.Destination.c_str());
	if (pdst->isDirectory())
	{
		destination += pdst->getPath();
		if (destination[destination.length() - 1] != '/') {
			destination += '/';
		}
		destination += psrc->getFileName();
	} else {
		File *pdf = dynamic_cast<File*>(pdst);
		if (pdf == NULL) {
			throw MessageOnlyException("Unknown error");
		}
		if (pdf->exist()) {
			throw MessageOnlyException("Overwrite is not supported");
		} else {
			destination += pdf->getFileName();
		}

		if (job.CreateHardLink) {
			if (0 != link(psrc->getPath(), destination.c_str())) {
				char message[64];
				snprintf(message, 64, "hard link failed: %s", strerror(errno));
				throw MessageOnlyException(message);
			}
		} else if (job.CreateSymbolicLink) {
			if (0 != symlink(psrc->getPath(), destination.c_str())) {
				char message[64];
				snprintf(message, 64, "soft link failed: %s", strerror(errno));
				throw MessageOnlyException(message);
			}
		} else {
			File *psf = dynamic_cast<File*>(psrc);
			char message[64];
			int sfd = open(psf->getPath(), O_RDONLY);
			if (sfd < 0) {
				snprintf(message, 64, "open src failed: %s", strerror(errno));
				throw MessageOnlyException(message);
			}
			int dfd = creat(destination.c_str(), psf->mode());
			if (dfd < 0) {
				snprintf(message, 64, "create dest failed: %s", strerror(errno));
				throw MessageOnlyException(message);
			}

			char *buff = new char[psf->blockSize()];
			ssize_t ret;
			while (0 < (ret = read(sfd, buff, psf->blockSize()))) {
				ssize_t wret = write(dfd, buff, ret);
				if (wret != ret) {
					delete buff;
					close(dfd);
					close(sfd);
					snprintf(message, 64, "writing dest failed: %s", strerror(errno));
					throw MessageOnlyException(message);
				}
			}

			if (ret < 0) {
				delete buff;
				close(dfd);
				close(sfd);
				snprintf(message, 64, "reading srcfailed: %s", strerror(errno));
				throw MessageOnlyException(message);
			}

			delete buff;
			close(dfd);
			close(sfd);
		}
	}

	return 0;
}
