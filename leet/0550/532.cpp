#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
	int findPairs(vector<int>& nums, int k) {
		sort(nums.begin(), nums.end());
		int ilast = 0x7fffffff, pos = 0;
		int cnt = 0;
		for (int i=0; i<nums.size(); ++i) {
			if (ilast == nums[i]) { continue; }
			ilast = nums[i];
			for (pos=max(pos, i+1); pos<nums.size(); ++pos) {
				if (nums[pos]-nums[i] == k) {
					++cnt; break;
				} else if (nums[pos]-nums[i] > k) {
					break;
				}
			}
		}

		return cnt;
	}
};

int main() {
	int n, k; cin >> n;
	vector<int> nums(n);
	for (int i=0; i<n; ++i) { cin >> nums[i]; }
	cin >> k;
	Solution sol;
	cout << sol.findPairs(nums, k) << endl;
	return 0;
}
