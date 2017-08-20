class Solution {
public:
	vector<int> plusOne(vector<int>& digits) {
		int sz = digits.size();
		bool pass = true;
		for (int i=sz-1; i>=0 && pass; --i) {
			if (++digits[i] > 9) {
				digits[i] -= 10;
			} else {
				pass = false;
			}
		}

		vector<int> ans;
		if (pass) { ans.push_back(1); }
		for (auto v : digits) { ans.push_back(v); }
		return ans;
	}
};
