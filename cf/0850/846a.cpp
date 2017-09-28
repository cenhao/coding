#include <bits/stdc++.h>
using namespace std;

#define MAXN 100
int games[MAXN], rezcnt[MAXN];

int main() {
	int n; scanf("%d", &n);
	for (int i=0; i<n; ++i) { scanf("%d", &games[i]); }

	memset(rezcnt, 0, sizeof(rezcnt));
	int cnt = 0;
	for (int i=n-1; i>=0; --i) {
		if (games[i] == 0) { ++cnt; }
		rezcnt[i] = cnt;
	}

	int mx = cnt;
	cnt = 0;
	for (int i=0; i<n; ++i) {
		if (games[i] == 0) {
			++cnt;
		} else {
			mx = max(mx, n-i-rezcnt[i]+cnt);
		}
	}

	printf("%d\n", mx);
	return 0;
}
