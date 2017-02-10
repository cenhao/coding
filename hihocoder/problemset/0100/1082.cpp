#include <cctype>
#include <cstdio>
#include <cstring>
using namespace std;

#define MAXS 200
#define PLEN 9

const char pattern[] = "marshtomp";
const char replace[] = "fjxmlhx";
int fail[PLEN];
char buffer[MAXS+10];
char output[MAXS+10];

void init() {
	int cur = fail[0] = -1;
	for (int i=1, end=strlen(pattern); i<end; ++i) {
		while (cur != -1 && pattern[cur+1] != pattern[i]) { cur = fail[cur]; }
		if (pattern[cur+1] == pattern[i]) { ++cur; }
		fail[i] = cur;
	}
}

int main() {
	init();
	int rlen = strlen(replace);
	while (NULL != fgets(buffer, sizeof(buffer), stdin)) {
		int len = strlen(buffer);
		buffer[--len] = 0;

		int cur = -1;
		int pos = 0;
		for (int i=0; i<len; ++i) {
			output[pos++] = buffer[i];
			while (cur != -1 && pattern[cur+1] != tolower(buffer[i])) { cur = fail[cur]; }
			if (pattern[cur+1] == tolower(buffer[i])) { ++cur; }
			if (cur == PLEN-1) {
				pos -= PLEN;
				memcpy(&output[pos], replace, rlen);
				pos += rlen;
			}
		}

		output[pos] = 0;
		printf("%s\n", output);
	}

	return 0;
}
