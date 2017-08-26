#include <bits/stdc++.h>
using namespace std;

#define MAXN 200000
int st[MAXN], scnt = 0;

int main() {
	int n; scanf("%d", &n);
	bool allow_pass = true;;
	int cur_spd, ans = 0, cnt = 0;
	for (int i=0; i<n; ++i) {
		int cmd; scanf("%d", &cmd);
		if (cmd == 1) {
			scanf("%d", &cur_spd);
		} else if (cmd == 2) {
			ans += cnt;
			cnt = 0;
		} else if (cmd == 3) {
			int l; scanf("%d", &l);
			st[scnt++] = l;
		} else if (cmd == 4) {
			cnt = 0;
		} else if (cmd == 5) {
			scnt = 0;
		} else {
			++cnt;
		}

		while (scnt > 0 && st[scnt-1] < cur_spd) {
			++ans; --scnt;
		}
	}

	printf("%d\n", ans);
	return 0;
}
