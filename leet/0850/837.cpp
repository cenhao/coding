#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	double new21Game(int n, int k, int w) {
		if (n == 0) { return 1.0; }
		vector<double> dp(n+1);
		dp[0] = k > 0 ? 1 : 0;
		double sm = dp[0];
		for (int i=1; i<=n; ++i) {
			if (i-w-1>=0 && i-w-1<k) { sm -= dp[i-w-1]; }
			dp[i] = sm / w;
			if (i < k) { sm += dp[i]; }
		}
		double ans = 0;
		dp[0] = 1;
		for (int i=k; i<=n; ++i) { ans += dp[i]; }
		return ans;
	}
};

int main() {
	int n, k, w; cin >> n >> k >> w;
	Solution sol;
	cout << sol.new21Game(n, k, w) << endl;
	return 0;
}
