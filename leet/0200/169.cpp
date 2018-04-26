class Solution {
public:
	int majorityElement(vector<int>& nums) {
		int cnt = 0, val;
		for (auto n: nums) {
			if (cnt == 0) {
				val = n;
				++cnt;
			} else {
				if (n == val) {
					++cnt;
				} else {
					--cnt;
				}
			}
		}

		int cnt = 0;
		for (auto n: nums) { if (n == val) { ++cnt; } }
		return (cnt > nums.size() / 2) ? val : -1;
	}
};
