class Solution {
public:
	string removeDuplicateLetters(string s) {
		if (s.length() == 0) { return s; }
		vector<int> cnt(26, 0);
		int dccnt = 0;

		for (int i=s.length()-1; i>=0; --i) {
			if (cnt[s[i]-'a']++ == 0) { ++dccnt; }
		}
		int pick = 256, tmp = dccnt;
		for (int i=0; i<s.length() && tmp==dccnt; ++i) {
			if (s[i] < pick) { pick = s[i]; }
			if (--cnt[s[i]-'a'] == 0) { --tmp; }
		}
		string ss;
		int pos = 0;
		for (; pos<s.length(); ++pos) {
			if (s[pos] == pick) { break; }
		}
		for (; pos<s.length(); ++pos) {
			if (s[pos] != pick) { ss += s[pos]; }
		}
		ss = removeDuplicateLetters(move(ss));
		return char(pick) + ss;
	}
};
