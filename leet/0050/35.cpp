#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int searchInsert(vector<int>& nums, int target) {
		auto it = lower_bound(nums.begin(), nums.end(), target);
		return distance(nums.begin(), it);
	}
};

int main() {
	int n; cin >> n;
	vector<int> nums(n);
	for (int i=0; i<n; ++i) { cin >> nums[i]; }
	int t; cin >> t;
	Solution sol;
	cout << sol.searchInsert(nums, t) << endl;
	return 0;
}
