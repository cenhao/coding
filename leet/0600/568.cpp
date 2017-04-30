#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int maxVacationDays(vector<vector<int>>& flights, vector<vector<int>>& days) {
		vector<vector<int>> dp(days[0].size(), vector<int>(flights.size(), 0));
		vector<vector<bool>> ok(days[0].size(), vector<bool>(flights.size(), false));
		// init
		for (int i=0; i<flights.size(); ++i) {
			if (i == 0 || flights[0][i] != 0) {
				dp[0][i] = days[i][0];
				ok[0][i] = true;
			}
		}

		for (int i=1; i<days[0].size(); ++i) {
			for (int j=0; j<flights.size(); ++j) {
				for (int k=0; k<flights.size(); ++k) {
					if (ok[i-1][k] && (j==k || flights[k][j])) {
						dp[i][j] = max(dp[i][j], dp[i-1][k] + days[j][i]);
						ok[i][j] = true;
					}
				}
			}
		}

		int mx = 0;
		for (int i=0; i<flights.size(); ++i) {
			if (ok[days[0].size()-1][i]) {
				mx = max(dp[days[0].size()-1][i], mx);
			}
		}

		return mx;
	}
};

int main() {
	int n, k; scanf("%d %d", &n, &k);
	vector<vector<int>> f(n, vector<int>(n));
	vector<vector<int>> d(k, vector<int>(n));
	for (int i=0; i<n; ++i) { for (int j=0; j<n; ++j) { cin >> f[i][j]; } }
	for (int i=0; i<k; ++i) { for (int j=0; j<n; ++j) { cin >> d[i][j]; } }
	Solution sol;
	cout << sol.maxVacationDays(f, d);
	return 0;
}
