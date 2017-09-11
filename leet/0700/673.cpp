#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int findNumberOfLIS(vector<int>& nums) {
		vector<int> dp(nums.size(), 0x7fffffff);
		vector<int> occ(nums.size(), 0);
		int mmxl = 0;
		for (int i=0; i<nums.size(); ++i) {
			int mxl = 0, cnt = 1;
			for (int j=0; j<i; ++j) {
				if (nums[i] > nums[j]) {
					if (dp[j] > mxl) {
						cnt = occ[j];
						mxl = dp[j];
					} else if (dp[j] == mxl) {
						cnt += occ[j];
					}
				}
			}

			dp[i] = mxl + 1;
			occ[i] = cnt;
			mmxl = max(mmxl, dp[i]);
		}

		int ans = 0;
		for (int i=0; i<nums.size(); ++i) {
			if (dp[i] == mmxl) { ans += occ[i]; }
		}

		return ans;
	}
};

int main() {
	int n; cin >> n;
	vector<int> nums(n);
	for (int i=0; i<n; ++i) { cin >> nums[i]; }
	Solution sol;
	cout << sol.findNumberOfLIS(nums) << endl;
	return 0;
}
