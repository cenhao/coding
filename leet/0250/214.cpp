class Solution {
public:
	string shortestPalindrome(string s) {
		int len = s.length();
		if (len == 0) { return s; }
		vector<int> dp(2+2*len, -1);
		dp[0] = dp[1] = 0;
		string tmp(2+2*len, 0);
		tmp[0] = 1;
		for (int i=0; i<len; ++i) { tmp[2+i*2] = s[i]; }

		int ctr = 1;
		for (int i=2, ed=2+len*2; i<ed; ++i) {
			int cur = ctr;
			while (cur+dp[cur]<i-1 || tmp[i]!=tmp[cur-(i-cur)]) {
				++cur;
				dp[cur] = min(dp[ctr-(cur-ctr)], i-1-cur);
			}
			++dp[cur];
			ctr = cur;
		}

		for (int i=ctr+1, ed=2+len*2; i<ed; ++i) {
			dp[i] = min(dp[ctr-(i-ctr)], ed-1-i);
		}

		int mx = 0;
		for (int i=2, ed=2+len*2; i<ed; ++i) {
			if (i-dp[i] <= 2) {
				mx = max(mx, (dp[i]+i-2)/2);
			}
		}

		string ext = s.substr(mx+1);
		reverse(ext.begin(), ext.end());
		return ext + s;
	}
};
