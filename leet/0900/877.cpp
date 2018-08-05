#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	bool stoneGame(vector<int>& piles) {
		int sz = piles.size();
		vector<vector<int>> dp(2, vector<int>(sz, 0));
		vector<vector<int>> sm(2, vector<int>(sz, 0));
		for (int i=0; i<sz; ++i) { sm[1][i] = dp[1][i] = piles[i]; }
		for (int i=2; i<=sz; ++i) {
			int cur = i & 1, pre = (i+1) & 1;
			for (int j=0; j+i<=sz; ++j) {
				sm[cur][j] = piles[j] + sm[pre][j+1];
				dp[cur][j] = max(piles[j]+sm[pre][j+1]-dp[pre][j+1], piles[j+i-1]+sm[pre][j]-dp[pre][j]);
			}
		}
		int cur = sz & 1;
		return dp[cur][0] > sm[cur][0]-dp[cur][0];
	}
};

int main() {
	vector<int> p = {3, 7, 2, 3};
	Solution sol;
	cout << sol.stoneGame(p) << endl;
	return 0;
}
