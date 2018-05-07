class Solution {
public:
	int minSubArrayLen(int s, vector<int>& nums) {
		int ans = 0, sm = 0;
		for (int i=0, l=0; i<nums.size(); ++i) {
			sm += nums[i];
			while (l<i && sm-nums[l]>=s) {
				sm -= nums[l++];
			}

			if (sm >= s && (ans==0 || (i-l+1) < ans)) {
				ans = i-l+1;
			}
		}

		return ans;
	}
};
