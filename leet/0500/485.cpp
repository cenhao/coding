#include <algorithm>
#include <vector>
using namespace std;

class Solution {
	public:
	int findMaxConsecutiveOnes(vector<int>& nums) {
		int cnt = 0, mx = 0;

		nums.push_back(0);
		for (int i=0; i<nums.size(); ++i) {
			if (nums[i] == 0) {
				mx = max(mx, cnt);
				cnt = 0;
			} else {
				++cnt;
			}
		}

		return mx;
	}
};
