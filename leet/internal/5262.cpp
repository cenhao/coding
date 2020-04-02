#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int64_t dfs(int64_t n, int w, vector<vector<int64_t>> &dp) {
		if (w == 0) { return 0; }
		if (dp[n][w] == -1) {
			int req = (w-1)*3+2;
			dp[n][w] = dfs(n, w-1, dp);
			if (n >= req) {
				dp[n][w] += (n==req) ? 1 : 0;
				dp[n][w] += dfs(n-req, w-1, dp);
			}
		}

		return dp[n][w];
	}
	int numTowerCards(int n) {
		vector<vector<int64_t>> dp(n+1, vector<int64_t>(n+1, -1));
		return dfs(n, n, dp);
	}
};

int main() {
	int n; cin >> n;
	Solution sol;
	cout << sol.numTowerCards(n) << endl;
	return 0;
}
