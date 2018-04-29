class Solution {
public:
	bool is_vowel(char c) {
		c = tolower(c);
		return c=='a' || c=='e' || c=='i' || c=='o' || c=='u';
	}
	string toGoatLatin(string s) {
		string ans, buff;
		int len = s.length(), cnt = 0;;
		for (int i=0; i<=len; ++i) {
			if (i==len || s[i]==' ') {
				if (buff.length() > 0) {
					++cnt;
					if (is_vowel(buff[0])) {
						buff += "ma";
						ans += move(buff);
					} else {
						string tmp = move(buff.substr(1) + buff[0]);
						tmp += "ma";
						ans += move(tmp);
					}
					buff = "";
					for (int j=0; j<cnt; ++j) { ans += 'a'; }
				}
				if (i < len) ans += s[i];
			} else {
				buff += s[i];
			}
		}
		return ans;
	}
};
