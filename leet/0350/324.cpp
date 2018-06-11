#include <bits/stdc++.h>
using namespace std;

class Solution {
	int quick_select(vector<int> &nums, int k) {
		int l = 0, r = nums.size()-1;
		while (l <= r) {
			int pick = nums[r];
			int lp = l;
			for (int i=l; i<r; ++i) {
				if (nums[i] < pick) { swap(nums[lp++], nums[i]); }
			}
			swap(nums[lp], nums[r]);
			if (lp < k) {
				l = lp + 1;
			} else if (lp > k) {
				r = lp - 1;
			} else {
				return nums[lp];
			}
		}
		return nums[l];
	}
public:
	void wiggleSort(vector<int>& nums) {
		int sz = nums.size();
		int half = sz / 2;
		int mid = quick_select(nums, half);
		int sidx = (sz&1) ? sz-1 : sz-2, lidx = 1;
		for (int i=0, idx=sidx; i<sz; ++i) {
			if (idx < 0) { idx = (sz&1) ? sz-2 : sz-1; }
			if (nums[idx] < mid) {
				swap(nums[idx], nums[sidx]);
				sidx -= 2;
				idx -= 2;
			} else if (nums[idx] > mid) {
				swap(nums[idx], nums[lidx]);
				lidx += 2;
			} else {
				idx -= 2;
			}
		}
	}
};

int main() {
	int n; cin >> n;
	vector<int> nums(n);
	for (int i=0; i<n; ++i) { cin >> nums[i]; }
	Solution sol;
	sol.wiggleSort(nums);
	for (auto nu: nums) { cout << nu << " "; }
	cout << endl;
	return 0;
}
