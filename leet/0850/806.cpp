class Solution {
public:
	vector<int> numberOfLines(vector<int>& widths, string S) {
		int lcnt = 0, sp = 0;
		for (auto c: S) {
			if (sp + widths[c-'a'] > 100) {
				++lcnt;
				sp = 0;
			}
			sp += widths[c-'a'];
		}

		vector<int> ans = { lcnt + 1, sp };
		return ans;
	}
};
