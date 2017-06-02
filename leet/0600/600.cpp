#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int findIntegers(int num) {
		int dp[32][2];
		dp[0][0] = dp[0][1] = 1;
		for (int i=1; i<32; ++i) {
			dp[i][0] = dp[i-1][0] + dp[i-1][1];
			dp[i][1] = dp[i-1][0];
		}

		int pos = 0;
		while ((1<<pos) <= num) { ++pos; }

		int ans = 0, ocnt = 0;
		for (int i=pos; i>0 && ocnt < 2; --i) {
			int nxto = (num & (1<<(i-1)));
			if (nxto) {
				ans += dp[i-1][0];
				++ocnt;
			} else {
				ocnt = max(ocnt-1, 0);
			}
		}

		if (ocnt < 2) { ++ans; }

		return ans;
	}
};

int main() {
	int n; cin >> n;
	Solution sol;
	cout << sol.findIntegers(n) << endl;
	return 0;
}
