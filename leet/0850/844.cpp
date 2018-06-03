class Solution {
public:
	bool backspaceCompare(string s, string t) {
		string ss;
		for (auto c: s) {
			if (c != '#') {
				ss.push_back(c);
			} else {
				if (!ss.empty()) { ss.pop_back(); }
			}
		}
		string tt;
		for (auto c: t) {
			if (c != '#') {
				tt.push_back(c);
			} else {
				if (!tt.empty()) { tt.pop_back(); }
			}
		}

		return tt == ss;
	}
};
