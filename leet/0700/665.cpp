class Solution {
public:
	bool checkPossibility(vector<int>& nums) {
		bool used = false, possible = true;
		for (int i=0; i<nums.size(); ++i) {
			if (i!=0 && nums[i]<nums[i-1]) {
				if (used) {
					possible = false;
					break;
				}

				used = true;
				int l=0, r=i-1;
				while (l <= r) {
					int m = (l + r) >> 1;
					if (nums[m] > nums[i]) {
						r = m - 1;
					} else {
						l = m + 1;
					}
				}

				if (l < i-1) {
					nums[i] = nums[i-1];
				}
			}
		}

		return possible;
	}
};
