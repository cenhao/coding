#include <bits/stdc++.h>
using namespace std;

#define MAXN 1000000
char buff[MAXN+10];
int ml[MAXN];

int main() {
	fgets(buff, sizeof(buff), stdin);
	int len = strlen(buff);
	buff[--len] = 0;

	stack<int> open;
	int mx = 0, cnt = 0;
	for (int i=0; i<len; ++i) {
		if (buff[i] == '(') {
			ml[i] = 0;
			open.push(i);
		} else {
			ml[i] = 0;
			if (open.empty()) { continue; }
			int pos = open.top(); open.pop();
			ml[i] = i - pos + 1 + ((pos == 0) ? 0 : ml[pos-1]);

			if (ml[i] > mx) {
				cnt = 1;
				mx = ml[i];
			} else if (ml[i] == mx) {
				++cnt;
			}
		}
	}

	if (mx == 0) { cnt = 1; }
	printf("%d %d\n", mx, cnt);
	return 0;
}
