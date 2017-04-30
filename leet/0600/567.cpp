class Solution {
public:
	bool checkInclusion(string s1, string s2) {
		int cnt[26]; memset(cnt, 0, sizeof(cnt));
		for (int i=0; i<s1.length(); ++i) {
			++cnt[s1[i]-'a'];
		}

		int check[26]; memset(check, 0, sizeof(check));
		for (int h=0, r=0; h<s2.length(); ++h) {
			int idx = s2[h] - 'a';
			++check[idx];
			while (r<=h && check[idx] > cnt[idx]) {
				--check[s2[r]-'a'];
				++r;
			}

			if (h-r+1 == s1.length()) { return true; }
		}

		return false;
	}
};
