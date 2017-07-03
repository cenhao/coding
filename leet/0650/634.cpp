#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int findDerangement(int n) {
		vector<int> dp(n+1);
		dp[1] = 0; dp[2] = 1;
		for (int i=3; i<=n; ++i) {
			int64_t tmp = (int64_t(i-1) * (dp[i-1] + dp[i-2])) % 1000000007;
			dp[i] = tmp;
		}

		return dp[n];
	}
};

int main() {
	int n; cin >> n;
	Solution sol;
	cout << sol.findDerangement(n) << endl;
	return 0;
}
