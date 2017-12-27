#include <bits/stdc++.h>
using namespace std;

#define MAXN 50
#define MAXM 1000

int days[12] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30};

int mt[MAXN][MAXM+1];

int main() {
	for (int i=1; i<12; ++i) { days[i] += days[i-1]; }
	int t; scanf("%d", &t);
	while (t--) {
		int n, m; scanf("%d%d", &n, &m);
		for (int i=0; i<n; ++i) { mt[i][0] = 0; }
		for (int i=0; i<m; ++i) {
			char date[8];
			int a, b;
			scanf("%s %d %d", date, &a, &b);
			--a; --b;
			int mon = (date[0]-'0') * 10 + date[1]-'0' - 1;
			int d = (date[3]-'0') * 10 + date[4]-'0';
			mt[a][++mt[a][0]] = days[mon] + d;
			mt[b][++mt[b][0]] = days[mon] + d;
		}

		bool ok = true;
		for (int i=0; i<n && ok; ++i) {
			sort(&mt[i][1], (&mt[i][1])+mt[i][0]);
			for (int j=2; j<=mt[i][0] && ok; ++j) {
				if (mt[i][j]-mt[i][j-1] <= 1) { ok = false; }
			}
		}

		printf("%s\n", ok ? "YES" : "NO");
	}
	return 0;
}
