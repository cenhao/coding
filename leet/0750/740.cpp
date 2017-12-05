#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int deleteAndEarn(vector<int>& nums) {
		const int maxn = 11;
		sort(nums.begin(), nums.end());
		vector<int> cnt(maxn, 0);
		int sz = nums.size();
		for (int i=0; i<sz; ++i) { ++cnt[nums[i]]; }

		vector<int> dp(maxn, 0);
		int mx = 0;
		for (int i=1; i<maxn; ++i) {
			dp[i] = i * cnt[i];
			if (i-2 >= 0) { dp[i] += dp[i-2]; }
			if (i > 0) { dp[i] = max(dp[i], dp[i-1]); }
			mx = max(dp[i], mx);
		}

		return mx;
	}
};

int main() {
	int n; cin >> n;
	vector<int> nums(n); for (int i=0; i<n; ++i) { cin >> nums[i]; }
	Solution sol;
	cout << sol.deleteAndEarn(nums) << endl;
	return 0;
}
