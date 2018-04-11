class Solution {
public:
	int maxProduct(vector<int>& nums) {
		int mx = 0, nmn = 0, ans = nums[0];
		for (auto n: nums) {
			ans = max(ans, n);
			if (n >= 0) {
				mx = max(mx*n, n);
				ans = max(mx, ans);
				nmn = min(0, nmn*n);
			} else {
				int tmp = nmn;
				nmn = min(mx*n, n);
				mx = max(tmp*n, 0);
				if (mx != 0) { ans = max(mx, ans); }
			}
		}
		return ans;
	}
};
