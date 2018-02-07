class Solution {
public:
	bool isPalindrome(string s) {
		int len = s.length();
		for (int i=0; i<len; ++i) { s[i] = tolower(s[i]); }
		int h = 0, r = len-1;
		bool ok = true;
		while (h < r && ok) {
			if (!isalnum(s[h])) {
				++h;
				continue;
			}
			if (!isalnum(s[r])) {
				--r;
				continue;
			}
			if (s[h] != s[r]) { ok = false; }
			++h; --r;
		}

		return ok;
	}
};
