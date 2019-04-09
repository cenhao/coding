class Solution {
public:
	string removeOuterParentheses(string s) {
		string ans = "";
		int cnt = 0;
		for (auto c: s) {
			if (c == '(') {
				++cnt;
				if (cnt > 1) { ans += c; }
			} else {
				if (cnt > 1) { ans += c; }
				--cnt;
			}
		}

		return ans;
	}
};
