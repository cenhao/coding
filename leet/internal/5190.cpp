class Solution {
public:
	string scan(string &s, int &pos) {
		string ret = "";
		for (; pos<s.length() && s[pos]!=')'; ++pos) {
			if (s[pos] == '(') {
				string ss = move(scan(s, ++pos));
				reverse(ss.begin(), ss.end());
				ret += ss;
			} else {
				ret += s[pos];
			}
		}

		return ret;
	}
	string reverseParentheses(string s) {
		int pos = 0;
		return move(scan(s, pos));
	}
};
