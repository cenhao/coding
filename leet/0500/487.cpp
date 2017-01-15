#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
	public:
	int findMaxConsecutiveOnes(vector<int>& nums) {
		int dp[10001][2];
		dp[0][0] = dp[0][1] = 0;
		int mx = 0;

		for (int i=1; i<=nums.size(); ++i) {
			if (nums[i-1] == 0) {
				dp[i][0] = 0;
				dp[i][1] = dp[i-1][0] + 1;
			} else {
				dp[i][0] = dp[i-1][0] + 1;
				dp[i][1] = dp[i-1][1] + 1;
			}

			mx = max(mx, dp[i][1]);
		}

		return mx;
	}
};

int main() {
	int n; cin >> n;
	vector<int> vec(n);
	for (int i=0; i<n; ++i) { cin >> vec[i]; }
	Solution sol;
	cout << sol.findMaxConsecutiveOnes(vec) << endl;
	return 0;
}
