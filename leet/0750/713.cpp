#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int numSubarrayProductLessThanK(vector<int>& nums, int k) {
		int sz = nums.size();
		int prod = 1, r = 0, ans = 0;
		for (int i=0; i<sz; ++i) {
			prod *= nums[i];
			while (r <= i && prod >= k) { prod /= nums[r++]; }
			ans += i - r + 1;
		}

		return ans;
	}
};

int main() {
	int n, k; cin >> n >> k;
	vector<int> nums(n, 0);
	for (int i=0; i<n; ++i) {
		cin >> nums[i];
	}
	Solution sol;
	cout << sol.numSubarrayProductLessThanK(nums, k) << endl;
	return 0;
}
