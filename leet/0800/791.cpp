#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
	string customSortString(string S, string T) {
		int slen = S.length();
		int cnt[26];
		memset(cnt, 0, sizeof(cnt));
		int tlen = T.length();
		for (int i=0; i<tlen; ++i) { ++cnt[T[i]-'a']; }
		string ans(tlen, ' ');
		int pos = 0;
		for (int i=0; i<slen; ++i) {
			for (int j=0; j<cnt[S[i]-'a']; ++j) {
				ans[pos++] = S[i];
			}
			cnt[S[i]-'a'] = 0;
		}

		for (int i=0; i<26; ++i) {
			for (int j=0; j<cnt[i]; ++j) {
				ans[pos++] = 'a' + i;
			}
		}

		return ans;
	}
};

int main() {
	string s, t; cin >> s >> t;
	Solution sol;
	cout << sol.customSortString(s, t);
	return 0;
}
