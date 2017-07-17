class Solution {
public:
	double findMaxAverage(vector<int>& nums, int k) {
		int sum = 0;
		int sz = nums.size(), mx = -1000000000;
		bool set = false;
		for (int i=0; i<sz; ++i) {
			sum += nums[i];
			if (i - k >= 0) { sum -= nums[i-k]; }
			if (i >= k-1) { mx = max(sum, mx); }
		}

		return mx / double(k);
	}
};
