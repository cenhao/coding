/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */

class Solution {
public:
    /**
     * @param l: The length of the matrix
     * @param w: The width of the matrix
     * @param points: three points 
     * @return: The sum of the paths sum
     */
    long long calculationTheSumOfPath(int l, int w, vector<Point> &points) {
		vector<vector<vector<int>>> dp(l+1, vector<vector<int>>(w+1, vector<int>(4, 0)));
		vector<vector<bool>> mk(l+1, vector<bool>(w+1, false));
		const int mod = 1000000007;
		for (auto &p: points) { mk[p.x][p.y] = true; }
		dp[1][1][mk[1][1] ? 1:0] = 1;
		for (int i=1; i<=l; ++i) {
			for (int j=1; j<=w; ++j) {
				if (mk[i][j]) {
					for (int k=0; k<3; ++k) {
						dp[i][j][k+1] = (dp[i][j][k+1]+dp[i-1][j][k]) % mod;
						dp[i][j][k+1] = (dp[i][j][k+1]+dp[i][j-1][k]) % mod;
					}
				} else {
					for (int k=0; k<4; ++k) {
						dp[i][j][k] = (dp[i][j][k]+dp[i-1][j][k]) % mod;
						dp[i][j][k] = (dp[i][j][k]+dp[i][j-1][k]) % mod;
					}
				}
			}
		}

		return dp[l][w][3];
    }
};
