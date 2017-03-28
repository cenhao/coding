#include <bits/stdc++.h>
using namespace std;

#define MAXS 100000

char buff[MAXS+1];

inline int get_id(char c) {
	return (c == 'h') ? 0 : ((c == 'i') ? 1 : 2);
}

inline int get_need(char c) {
	return (c == 'h') ? 2 : 1;
}

int main() {
	scanf("%s", buff);
	int r = 0;
	int cnt[3] = { 0, 0, 0 };
	int mn = MAXS+1;
	for (int i=0, end=strlen(buff); i<end; ++i) {
		if (buff[i] == 'h' || buff[i] == 'i' || buff[i] == 'o') {
			++cnt[get_id(buff[i])];
		}

		while (r < i) {
			if (buff[r]=='h' || buff[r]=='i' || buff[r]=='o') {
				int id = get_id(buff[r]);
				if (cnt[id] > get_need(buff[r])) {
					--cnt[id];
				} else {
					break;
				}
			}

			++r;
		}

		if (cnt[0] == 2 && cnt[1] == 1 && cnt[2] == 1) {
			mn = min(mn, i-r+1);
		}
	}

	printf("%d\n", (mn == MAXS+1) ? -1 : mn);
	return 0;
}
