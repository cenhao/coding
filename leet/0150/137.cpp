class Solution {
public:
	int singleNumber(vector<int>& nums) {
		int ans = 0;
		for (int i=0; i<32; ++i) {
			int cnt = 0;
			for (auto n: nums) {
				cnt += (n >> i) & 1;
			}
			ans += (cnt % 3) << i;
		}

		return ans;
	}
};
