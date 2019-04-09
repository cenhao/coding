class Solution {
public:
	vector<int> twoSum(vector<int>& numbers, int target) {
		int l = 0, r = numbers.size() - 1;
		while (l < r) {
			int sm = numbers[l] + numbers[r];
			if (sm == target) { return {l+1, r+1}; }
			if (sm > target) {
				--r;
			} else {
				++l;
			}
		}

		return {0, 0};
	}
};
