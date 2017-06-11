#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
	int triangleNumber(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		int ans = 0, sz = nums.size();
		for (int i=0; i<sz-2; ++i) {
			if (nums[i] == 0) { continue; }
			int r = 0;
			for (int j=i+1; j<sz-1; ++j) {
				int sum = nums[i] + nums[j];
				r = max(r, j+1);
				for (; r<sz && nums[r]<sum; ++r);
				ans += r - j - 1;
			}
		}

		return ans;
	}
};

int main() {
	int n; cin >> n;
	vector<int> nums(n);
	for (int i=0; i<n; ++i) { cin >> nums[i]; }
	Solution sol;
	cout << sol.triangleNumber(nums) << endl;
	return 0;
}
