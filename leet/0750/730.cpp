/*
 * Let dp(i, j) be the answer for the string T = S[i:j].
 * The answer is the number of unique characters in T,
 * plus dp(next('a', i)+1, prev('a', j)-1), representing palindromes of the form "a.+a". and because "aa" is also acceptable, add extra one if next < prev.
 * plus dp(next('b', i) + 1, prev('b', j) - 1) representing "b_b", add one if needed, etc.
 *
 * Here, next('a', i) means the next index at or after i where A[next('a', i)] = 'a', and so on.
 */
class Solution {
public:
	int dfs(const string &s, vector<vector<int>> &dp, const vector<vector<int>> &dis,
			const vector<vector<int>> &nxt, const vector<vector<int>> &pre, int st, int ed) {
		if (st > ed) { return 0; }
		if (dp[st][ed] >= 0) { return dp[st][ed]; }
		dp[st][ed] = dis[st][ed];
		for (int i=0; i<4; ++i) {
			dp[st][ed] += dfs(s, dp, dis, nxt, pre, nxt[st][i]+1, pre[ed][i]-1);
			if (nxt[st][i] < pre[ed][i]) { ++dp[st][ed]; }
			dp[st][ed] %= 1000000007;
		}

		return dp[st][ed];
	}
	int countPalindromicSubsequences(string s) {
		int len = s.length();
		if (len == 0) { return 0; }

		vector<vector<int>> dp(len, vector<int>(len, -1));
		vector<vector<int>> nxt(len, vector<int>(4)), pre(len, vector<int>(4));
		vector<vector<int>> dis(len, vector<int>(len, 0));
		for (int i=0; i<len; ++i) { dis[i][i] = 1 << (s[i] - 'a'); }
		for (int i=0; i<len; ++i) {
			for (int j=i+1; j<len; ++j) { dis[i][j] = dis[i][j-1] | dis[j][j]; }
		}
		for (int i=0; i<len; ++i) {
			for (int j=i; j<len; ++j) {
				int cnt = 0;
				for (int k=0; k<4; ++k) {
					if (dis[i][j] & (1<<k)) { ++cnt; }
				}
				dis[i][j] = cnt;
			}
		}
		
		for (int i=0; i<4; ++i) {
			for (int j=0, v=-1; j<len; ++j) {
				if (s[j]-'a' == i) { v = j; }
				pre[j][i] = v;
			}
			for (int j=len-1, v=len; j>=0; --j) {
				if (s[j]-'a' == i) { v = j; }
				nxt[j][i] = v;
			}
		}

		return dfs(s, dp, dis, nxt, pre, 0, len-1);
	}
};
