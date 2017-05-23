#include <bits/stdc++.h>
using namespace std;

class FileSystem {
public:
	FileSystem() {
		m_root = new FolderEntry();
		m_root->Children.insert(pair<string, IEntry*>("", new FolderEntry()));
	}

	vector<string> ls(string path) {
		int start = 0;
		IEntry *pient;
		FolderEntry *pfent = m_root;
		while (start < path.length()) {
			string cur = move(readNextPath(path, start));
			auto it = pfent->Children.find(cur);
			pfent = dynamic_cast<FolderEntry*>(it->second);
			if (pfent == NULL) {
				vector<string> ans;
				ans.push_back(move(cur));
				return ans;
			}
		}

		vector<string> ans(pfent->Children.size());
		int i = 0;
		for (auto &kvp : pfent->Children) { ans[i++] = kvp.first; }
		return ans;
	}

	void mkdir(string path) {
		int start = 0;
		FolderEntry *pfent = m_root;
		while (start < path.length()) {
			string cur = move(readNextPath(path, start));
			auto it = pfent->Children.find(cur);
			if (it == pfent->Children.end()) {
				it = pfent->Children.insert(pair<string, IEntry*>(move(cur), new FolderEntry())).first;
			}
			pfent = (FolderEntry*)it->second;
		}
	}

	void addContentToFile(string filePath, string content) {
		int start = 0;
		IEntry *pient = m_root;
		while (start < filePath.length()) {
			string cur = move(readNextPath(filePath, start));
			FolderEntry *pfent = dynamic_cast<FolderEntry*>(pient);
			if (pfent == NULL) {
				// assert start >= path.length()
				break;
			}
			auto it = pfent->Children.find(cur);
			if (it == pfent->Children.end()) {
				IEntry *ptmp;
				if (start >= filePath.length()) {
					ptmp = new FileEntry();
				} else {
					ptmp = new FolderEntry();
				}
				it = pfent->Children.insert(pair<string, IEntry*>(move(cur), ptmp)).first;
			}
			pient = it->second;
		}

		FileEntry *pfient = dynamic_cast<FileEntry*>(pient);
		pfient->Content += content;
	}

	string readContentFromFile(string filePath) {
		int start = 0;
		IEntry *pient = m_root;
		while (start < filePath.length()) {
			string cur = move(readNextPath(filePath, start));
			FolderEntry *pfent = dynamic_cast<FolderEntry*>(pient);
			if (pfent == NULL) {
				// assert start >= path.length()
				break;
			}
			auto it = pfent->Children.find(cur);
			pient = it->second;
		}

		FileEntry *pfient = dynamic_cast<FileEntry*>(pient);
		return pfient->Content;
	}

	virtual ~FileSystem() {
		if (m_root != NULL) { delete m_root; }
		m_root = NULL;
	}
private:
	string readNextPath(const string &path, int &start) {
		for (int i=start; i<path.length(); ++i) {
			if (path[i] == '/') {
				int tmp = start;
				start = i+1;
				return path.substr(tmp, i-tmp);
			}
		}

		int tmp = start;
		start = path.length();
		return path.substr(tmp);
	}
	class IEntry {
	public:
		virtual ~IEntry() {};
	};
	class FileEntry : public IEntry {
	public:
		string Content;
		virtual ~FileEntry() {}
	};
	class FolderEntry : public IEntry {
	public:
		map<string, IEntry*> Children;
		virtual ~FolderEntry() {
			for (auto &kvp : Children) { delete kvp.second; }
			Children.clear();
		}
	};

	FolderEntry *m_root;
};

int main() {
	FileSystem fs;
	fs.mkdir("/goowmfn");
	auto a2 = fs.ls("/goowmfn");
	for (auto &s : a2) { cout << s << endl; }
	auto a1 = fs.ls("/");
	for (auto &s : a1) { cout << s << endl; }
	fs.mkdir("/z");
	auto a3 = fs.ls("/");
	for (auto &s : a3) { cout << s << endl; }
	fs.addContentToFile("/goowmfn/c", "shetopcy");
	auto a4 = fs.ls("/");
	for (auto &s : a4) { cout << s << endl; }
	auto a5 = fs.ls("/");
	for (auto &s : a5) { cout << s << endl; }
	auto a6 = fs.ls("/goowmfn/c");
	for (auto &s : a6) { cout << s << endl; }
	return 0;
}
