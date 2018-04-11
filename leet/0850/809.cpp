#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int expressiveWords(string s, vector<string>& w) {
		int sz = w.size(), len = s.length(), ans = 0;
		for (int i=0; i<sz; ++i) {
			int wlen = w[i].length();
			char last = w[i][0];
			int cnt = 0, spos = 0;
			bool ok = true;
			for (int j=0; j<=wlen; ++j) {
				if (j==wlen || w[i][j]!=last) {
					int scnt = 0;
					do {
						++spos; ++scnt;
					} while (spos<len && (spos==0 || s[spos]==s[spos-1]));
					if (last!=s[spos-1] || cnt>scnt || (scnt<3 && scnt!=cnt)) {
						ok = false;
						break;
					}
					if (j != wlen) { last = w[i][j]; }
					cnt = 0;
				}
				++cnt;
			}

			ok &= (spos >= len);

			ans += ok ? 1 : 0;
		}
		return ans;
	}
};

int main() {
	string s; cin >> s;
	int n; cin >> n;
	vector<string> w(n);
	for (int i=0; i<n; ++i) { cin >> w[i]; }
	Solution sol;
	cout << sol.expressiveWords(s, w) << endl;
	return 0;
}
