class Solution {
public:
	bool isValid(const string &s, int l, int r, bool d) {
		while (l < r) {
			if (s[l] != s[r]) { return !d && (isValid(s, l, r-1, true) || isValid(s, l+1, r, true)); }
			++l; --r;
		}
		return true;
	}
	bool validPalindrome(string s) {
		return isValid(s, 0, s.length()-1, false);
	}
};
