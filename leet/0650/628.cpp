#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int maximumProduct(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		bool pick = false;
		int sz = nums.size();
		int mx = nums[0] * nums[1] * nums[2];
		for (int i=1; i<=3; ++i) {
			int tmp = 1;
			for (int j=0; j<3-i; ++j) { tmp *= nums[j]; }
			for (int j=sz-1; j>=sz-i; --j) { tmp *= nums[j]; }
			mx = max(mx, tmp);
		}
		return mx;
	}
};

int main() {
	int n; cin >> n;
	vector<int> nums(n);
	for (int i=0; i<n; ++i) { cin >> nums[i]; }
	Solution sol;
	cout << sol.maximumProduct(nums);
	return 0;
}
