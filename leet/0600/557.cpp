class Solution {
public:
	string reverseWords(string s) {
		string ans = "";
		int sta = 0;
		for (int i=0; i<=s.length(); ++i) {
			if (i == s.length() || s[i] == ' ') {
				for (int j=i-1; j>=sta; --j) {
					ans += s[j];
				}

				if (i != s.length()) { ans += s[i]; }
				sta = i + 1;
			}
		}

		return ans;
	}
};
