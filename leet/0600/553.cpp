class Solution {
public:
	string toString(int n) {
		static char buff[8];
		snprintf(buff, sizeof(buff), "%d", n);
		return string(buff);
	}

	string optimalDivision(vector<int>& nums) {
		string ans = move(toString(nums[0]));

		for (int i=1; i<nums.size(); ++i) {
			ans += '/';
			if (i == 1 && i != nums.size()-1) { ans += '('; }
			ans += move(toString(nums[i]));
			if (i == nums.size()-1 && i != 1) { ans += ')'; }
		}

		return ans;
	}
};
