#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	bool search(vector<int>& nums, int target) {
		int sz = nums.size();
		if (sz <= 0) { return sz; }

		int l = 0, r = sz - 1;
		while (l <= r) {
			int m = (l + r) >> 1;
			if (nums[m] == target) { return true; }
			if (nums[l] == nums[m] && nums[m] == nums[r]) {
				++l; --r;
			} else if (nums[m] == nums[l]) {
				l = m + 1;
			} else if (nums[m] == nums[r]) {
				r = m - 1;
			} else if (nums[l] < nums[r]) {
				if (target < nums[m]) {
					r = m - 1;
				} else {
					l = m + 1;
				}
			} else if (nums[l] < nums[m]) {
				if (target > nums[m]) {
					l = m + 1;
				} else if (target >= nums[l]) {
					r = m - 1;
				} else {
					l = m + 1;
				}
			} else {
				if (target < nums[m]) {
					r = m - 1;
				} else if (target <= nums[r]) {
					l = m + 1;
				} else {
					r = m - 1;
				}
			}
		}

		return false;
	}
};

int main() {
	int n; cin >> n;
	vector<int> nums(n);
	for (int i=0; i<n; ++i) cin >> nums[i];
	int t; cin >> t;
	Solution sol;
	cout << sol.search(nums, t) << endl;
	return 0;
}
