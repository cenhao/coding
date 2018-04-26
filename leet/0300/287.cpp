class Solution {
public:
	int findDuplicate(vector<int>& nums) {
		int sz = nums.size();
		int l = 1, r = sz-1;
		while (l <= r) {
			int m = (l+r) >> 1;
			int cnt = 0, same = 0;
			for (auto n: nums) {
				cnt += (n <= m) ? 1 : 0;
				same += (n == m) ? 1 : 0;
			}

			if (same > 1) { return m; }
			if (cnt <= m) {
				l = m + 1;
			} else {
				r = m - 1;
			}
		}

		return -1; // not reach
	}
};
