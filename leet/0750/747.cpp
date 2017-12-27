class Solution {
public:
	int dominantIndex(vector<int>& nums) {
		int sz = nums.size();
		if (sz == 1) { return 0; }
		int mx = -1, smx = -1, mxp;
		for (int i=0; i<sz; ++i) {
			if (nums[i] > mx) {
				smx = mx;
				mx = nums[i]; mxp = i;
			} else if (nums[i] > smx) {
				smx = nums[i];
			}
		}

		return (mx >= smx * 2) ? mxp : -1;
	}
};
