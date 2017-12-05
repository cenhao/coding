#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int cherryPickup(vector<vector<int>>& grid) {
		int sz = grid.size(), hsz = grid[0].size();
		vector<vector<vector<int>>> dp(2, vector<vector<int>>(hsz, vector<int>(hsz, -1)));
		dp[1][0][0] = 0;
		for (int i=0; i<sz; ++i) {
			int cur = i & 1, pre = (i+1) & 1;
			for (int l=0; l<hsz; ++l) {
				for (int r=l; r<hsz; ++r) {
					int mx = dp[cur][l][r] = -1;
					if (grid[i][l] == -1 || grid[i][r] == -1) { continue; }
					if (dp[pre][l][r] >= 0) {
						int v = dp[pre][l][r]+grid[i][l]+((l==r)?0:grid[i][r]);
						mx = max(mx, v);
					}
					if (l == r && l > 0 && dp[cur][l-1][r-1] >= 0) {
						int v = dp[cur][l-1][r-1] + grid[i][l];
						mx = max(mx, v);
					}
					if (l > 0 && dp[cur][l-1][r] >= 0) {
						int v = dp[cur][l-1][r] + ((l==r)?0:grid[i][l]);
						mx = max(mx, v);
					}

					dp[cur][l][r] = mx;
				}
			}
			for (int l=0; l<hsz; ++l) {
				for (int r=l+1; r<hsz; ++r) {
					if (grid[i][l] == -1 || grid[i][r] == -1) { continue; }
					if (dp[cur][l][r-1] >= 0) {
						int v = dp[cur][l][r-1] + grid[i][r];
						dp[cur][l][r] = max(dp[cur][l][r], v);
					}
				}
			}
		}

		int cur = (sz-1) & 1;
		return max(0, dp[cur][hsz-1][hsz-1]);
	}
};

int main() {
	int n, m; cin >> n >> m;
	vector<vector<int>> mp(n, vector<int>(m));
	for (int i=0; i<n; ++i) {
		for (int j=0; j<m; ++j) { cin >> mp[i][j]; }
	}

	Solution sol;
	cout << sol.cherryPickup(mp) << endl;
	return 0;
}
