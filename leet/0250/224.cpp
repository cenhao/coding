class Solution {
public:
	int process(const string &s, int &pos) {
		int val = 0, tmp = 0;
		bool add = true;
		for (; pos<s.length() && s[pos]!=')'; ++pos) {
			if (s[pos] == '(') {
				++pos;
				tmp = process(s, pos);
			} else {
				if (s[pos] >= '0' && s[pos] <= '9') {
					tmp = tmp * 10 + s[pos] - '0';
				} else {
					val += add ? tmp : -tmp;
					tmp = 0;
					add = s[pos] == '+';
				}
			}
		}
		val += add ? tmp : -tmp;
		return val;
	}

	int calculate(string s) {
		string ns;
		for (auto c: s) { if (c != ' ') { ns += c; } }
		int pos = 0;
		return process(ns, pos);
	}
};
