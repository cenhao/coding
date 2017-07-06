class Solution {
public:
	int jump(vector<int>& nums) {
		int sz = nums.size();
		int nmx = -1, cmx = 0, cnt = 0;
		for (int i=0; i<sz; ++i) {
			if (i > cmx) {
				++cnt;
				cmx = nmx;
				nmx = -1;
			}
			nmx = max(nmx, i+nums[i]);
		}

		return cnt;
	}
};
