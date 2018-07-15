#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
		stations.push_back({target, 0});
		int sz = stations.size();
		vector<vector<int>> dp(sz+1, vector<int>(sz+1, -1));
		dp[0][0] = startFuel;

		for (int i=1; i<=sz; ++i) {
			int mx = -1;
			for (int j=0; j<=sz; ++j) {
				int pos = j==0 ? 0 : stations[j-1][0];
				int f = j==0 ? 0 : stations[j-1][1];
				if (mx-pos >= 0) { dp[i][j] = mx-pos+f; }
				if (dp[i-1][j] >= 0) { mx = max(mx, dp[i-1][j]+pos); }
			}
		}

		int ans = -1;
		for (int i=1; i<=sz; ++i) {
			if (dp[i][sz] >= 0) {
				ans = i-1;
				break;
			}
		}
		return ans;
	}
};

int main() {
	int t, s, n; cin >> t >> s >> n;
	vector<vector<int>> ss(n, vector<int>(2));
	for (int i=0; i<n; ++i) { cin >> ss[i][0] >> ss[i][1]; }
	Solution sol;
	cout << sol.minRefuelStops(t, s, ss) << endl;
	return 0;
}
