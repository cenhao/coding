class Solution {
public:
	vector<int> productExceptSelf(vector<int>& nums) {
		int sz = nums.size();
		vector<int> out(sz);
		for (int i=sz-1, pre=1; i>0; --i) {
			pre = out[i] = nums[i] * pre;
		}
		for (int i=0, pre=1; i<sz; ++i) {
			out[i] = pre * (i==sz-1 ? 1 : out[i+1]);
			pre *= nums[i];
		}
		return out;
	}
};
