#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	string reorganizeString(string s) {
		int len = s.length();
		int cnt[26]; memset(cnt, 0, sizeof(cnt));
		int idx[26];
		for (int i=0; i<len; ++i) { ++cnt[s[i]-'a']; }
		for (int i=0; i<26; ++i) { idx[i] = i; }
		sort(idx, idx+26, [cnt] (int i1, int i2) {
			return cnt[i1] > cnt[i2];
		});
		int cur = 0;
		for (int i=0; i<26; ++i) {
			for (int j=0; j<cnt[idx[i]]; ++j) {
				s[cur] = 'a' + idx[i];
				cur += 2;
				if (cur >= len) { cur = 1; }
			}
		}

		bool ok = true;
		for (int i=1; i<len-1; ++i) {
			if (s[i] == s[i-1] || s[i] == s[i+1]) { ok = false; }
		}

		return ok ? s : "";
	}
};

int main() {
	string in; cin >> in;
	Solution sol;
	cout << sol.reorganizeString(in) << endl;
	return 0;
}
