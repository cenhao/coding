class Solution {
public:
	vector<vector<int>> generateMatrix(int n) {
		vector<vector<int>> ans(n, vector<int>(n));
		int nxt = 0, end = n * n;
		int rl = n, dl = n, ll = -1, ul = 0; // limits
		int x = 0, y = 0;
		while (nxt < end) {
			for (int i=y; i<rl && nxt<end; ++i) {
				ans[x][i] = ++nxt;
			}

			y = --rl; ++x;

			for (int i=x; i<dl && nxt<end; ++i) {
				ans[i][y] = ++nxt;
			}

			x = --dl; --y;

			for (int i=y; i>ll && nxt<end; --i) {
				ans[x][i] = ++nxt;
			}

			y = ++ll; --x;

			for (int i=x; i>ul && nxt<end; --i) {
				ans[i][y] = ++nxt;
			}

			x = ++ul; ++y;
		}

		return ans;
	}
};
