#include <algorithm>
#include <vector>

class Solution {
	public:
	int minMoves2(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		long long mn, cnt = 0;
		for (int i=1; i<nums.size(); ++i) { cnt += nums[i] - nums[0]; }
		mn = cnt;
		for (int i=1; i<nums.size(); ++i) {
			long long v = (nums[i] - nums[i-1]);
			long long inc = v * i;
			long long dec = v * (nums.size() - i);
			cnt = cnt + inc - dec;
			mn = min(cnt, mn);
		}
		return (int)mn;
	}
};
