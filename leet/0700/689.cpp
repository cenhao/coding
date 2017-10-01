class Solution {
public:
	vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
		int sz = nums.size();
		vector<int> sm(sz, 0);
		vector<vector<int>> dp(3, vector<int>(sz, 0));
		vector<vector<int>> pick(3, vector<int>(sz, 0));

		sm[0] = nums[0];
		for (int i=1; i<sz; ++i) { sm[i] = sm[i-1]+nums[i]; }
		for (int i=k-1; i<sz; ++i) {
			dp[0][i] = sm[i] - (i==k-1 ? 0 : sm[i-k]);
		}

		for (int s=1; s<3; ++s) {
			for (int i=k*(s+1)-1; i<sz; ++i) {
				int v = sm[i] - sm[i-k];
				for (int j=k*s-1; j<=i-k; ++j) {
					int vv = v + dp[s-1][j];
					if (vv > dp[s][i]) {
						dp[s][i] = vv;
						pick[s][i] = j;
					}
				}
			}
		}

		int mx = 0, pos;
		for (int i=k*3-1; i<sz; ++i) {
			if (dp[2][i] > mx) {
				mx = dp[2][i];
				pos = i;
			}
		}

		vector<int> ans(3);
		for (int i=2; i>=0; --i) {
			ans[i] = pos-k+1;
			pos = pick[i][pos];
		}

		return ans;
	}
};
