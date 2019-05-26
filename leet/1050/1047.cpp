class Solution {
public:
	string removeDuplicates(string s) {
		int last = -1;
		for (auto c: s) {
			if (last>=0 && c==s[last]) {
				--last;
			} else {
				s[++last] = c;
			}
		}

		return s.substr(0, last+1);
	}
};
