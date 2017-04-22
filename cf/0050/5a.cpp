#include <bits/stdc++.h>
using namespace std;

#define MAXL 128
char line[MAXL];

int main() {
	unordered_set<string> hs;
	int sum = 0;
	while (NULL != fgets(line, sizeof(line), stdin)) {
		int len = strlen(line);
		line[--len] = 0;

		if (line[0] == '+') {
			string name = &line[1];
			hs.insert(move(name));
		} else if (line[0] == '-') {
			string name = &line[1];
			hs.erase(name);
		} else {
			int pos;
			for (int i=0; i<len; ++i) {
				if (line[i] == ':') {
					pos = i;
					break;
				}
			}

			sum += (len - pos - 1) * hs.size();
		}
	}

	printf("%d\n", sum);
	return 0;
}
