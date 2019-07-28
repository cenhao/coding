class Solution {
	int get(int pos, int mxm, int sz, int m, vector<vector<int>> &dp, vector<int> &sm) {
		if (pos > sz) { return 0; }
		if (dp[pos][mxm] != -1) { return dp[pos][mxm]; }
		int mx = 0;
		for (int i=1; i<=mxm && pos+i-1<=sz; ++i) {
			int gain = sm[pos+i-1] - sm[pos-1];
			int remain = sm[sz] - sm[pos+i-1];
			int nmxm = min(m, max(mxm, i*2));
			int sub = get(pos+i, nmxm, sz, m, dp, sm);
			mx = max(mx, gain+remain-sub);
		}
		return dp[pos][mxm] = mx;
	}

public:
	int stoneGameII(vector<int>& piles) {
		int sz = piles.size(), m = piles.size()*2;
		vector<vector<int>> dp(sz+1, vector<int>(m+1, -1));

		vector<int> sm(sz+1, 0);
		for (int i=1; i<=sz; ++i) { sm[i] = sm[i-1] + piles[i-1]; }
		return get(1, 2, sz, m, dp, sm);
	}
};
