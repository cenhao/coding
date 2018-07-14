class Solution {
public:
    /**
     * @param arr: the array
     * @return: the winner
     */
    int theGameOfTakeNumbers(vector<int> &arr) {
		int sz = arr.size();
		if (sz == 0) { return 1; }

		vector<vector<int>> dp(2, vector<int>(sz, 0));
		vector<vector<int>> sm(2, vector<int>(sz, 0));
		for (int i=0; i<sz; ++i) { dp[0][i] = sm[0][i] = arr[i]; }

		for (int i=1; i<sz; ++i) {
			int cur = i & 1, pre = (i+1) & 1;
			for (int j=sz-1-i; j>=0; --j) {
				sm[cur][j] = sm[pre][j+1] + arr[j];
				dp[cur][j] = sm[cur][j] - min(dp[pre][j], dp[pre][j+1]);
			}
		}

		return dp[1][0] >= sm[1][0] - dp[1][0] ? 1 : 2;
    }
};
