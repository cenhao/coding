/*
// LCS DP
class Solution {
public:
	string minWindow(string s, string t) {
		int len1 = s.length(), len2 = t.length();
		vector<vector<int>> dp(len2+1, vector<int>(len1+1, 0));
		vector<vector<int>> sta(len2+1, vector<int>(len1+1, 0));
		for (int i=0; i<len2; ++i) {
			for (int j=0; j<len1; ++j) {
				dp[i+1][j+1] = dp[i+1][j];
				sta[i+1][j+1] = sta[i+1][j];
				if (t[i] == s[j]) {
					if (dp[i][j] == i) {
						dp[i+1][j+1] = i + 1;
						if (i == 0) {
							sta[i+1][j+1] = j+1;
						} else {
							sta[i+1][j+1] = sta[i][j];
						}
					}
				}
			}
		}

		int mn = len1+1;
		int st = -1;
		for (int i=1; i<=len1; ++i) {
			if (sta[len2][i] <= 0) { continue; }
			int tlen = i-sta[len2][i]+1;
			if (tlen < mn) {
				mn = tlen;
				st = sta[len2][i];
			}
		}

		if (st < 0) { return ""; }
		return s.substr(st-1, mn);
	}
};
*/

// pre-process scanning
class Solution {
public:
	int nxt[20010][26];
	string minWindow(string s, string t) {
		int slen = s.length(), tlen = t.length();
		for (int i=0; i<26; ++i) { nxt[slen][i] = slen; }
		for (int i=slen-1; i>=0; --i) {
			for (int j=0; j<26; ++j) { nxt[i][j] = nxt[i+1][j]; }
			nxt[i][s[i]-'a'] = i;
		}

		int st = -1, mn = slen+1;
		for (int i=0, end=slen-tlen; i<=end; ++i) {
			int cur = i-1, cnt = 0;
			for (int j=0; j<tlen && cur<slen; ++j, ++cnt) {
				cur = nxt[cur+1][t[j]-'a'];
			}

			if (cur < slen && cnt == tlen) {
				if (cur-i+1 < mn) { mn = cur-i+1; st = i; }
			} else {
				break;
			}
		}

		return (st < 0) ? "" : s.substr(st, mn);
	}
};
