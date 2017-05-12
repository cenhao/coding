#include <bits/stdc++.h>
using namespace std;

#define MAXN 200
#define MAXX 200000

int r[MAXN];
int dp[MAXN+1][MAXX];

int main() {
	string n; cin >> n;
	int x, y; cin >> x >> y;

	r[0] = 1;
	for (int i=1; i<n.length(); ++i) { r[i] = (r[i-1] * 10) % x; }

	reverse(n.begin(), n.end());


	int len = n.length();
	memset(dp, -1, sizeof(dp));
	dp[0][0] = 0;
	for (int i=0; i<len; ++i) {
		int start, end;
		if (n[i] == '?') {
			start = (i==len-1 && i!=0) ? 1 : 0;
			end = 10;
		} else {
			start = n[i]-'0';
			end = start + 1;
		}

		for (int j=start; j<end; ++j) {
			for (int k=0; k<x; ++k) {
				if (dp[i][k] == -1) { continue; }
				int rr = (k + j*r[i]) % x;
				if (dp[i+1][rr] == -1) { dp[i+1][rr] = j; }
			}
		}
	}

	if (dp[len][y] == -1) {
		cout << "No solution\n";
	} else {
		for (int i=len, j=y; i>0; --i) {
			cout << dp[i][j];
			j = (j+x-dp[i][j]*r[i-1]);
			while (j<0) { j += x; }
			j %= x;
		}
		cout << endl;
	}
	return 0;
}
