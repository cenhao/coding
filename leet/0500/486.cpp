#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	bool PredictTheWinner(vector<int>& nums) {
		vector<vector<int>> dp(nums.size(), vector<int>(nums.size(), 0));
		vector<vector<int>> sum(nums.size(), vector<int>(nums.size(), 0));

		for (int i=0; i<nums.size(); ++i) {
			for (int j=0; j+i<nums.size(); ++j) {
				if (i == 0) {
					sum[j][i] = dp[j][i] = nums[j];
					continue;
				}

				sum[j][i] = sum[j][i-1] + nums[i+j];
				dp[j][i] = max(nums[j]+sum[j+1][i-1]-dp[j+1][i-1],
							   nums[j+i]+sum[j][i-1]-dp[j][i-1]);
			}
		}

		return dp[0][nums.size()-1]*2 >= sum[0][nums.size()-1];
	}
};

int main() {
	int n; cin >> n;
	vector<int> v(n);
	for (int i=0; i<n; ++i) { cin >> v[i]; }
	Solution sol;
	cout << sol.PredictTheWinner(v) << endl;
}
