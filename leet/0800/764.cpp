class Solution {
public:
	int orderOfLargestPlusSign(int N, vector<vector<int>>& mines) {
		vector<vector<bool>> g(N, vector<bool>(N, true));
		int sz = mines.size();
		for (int i=0; i<sz; ++i) { g[mines[i][0]][mines[i][1]] = false; }
		vector<vector<int>> l(N, vector<int>(N, 0)), r(N, vector<int>(N, 0)),
			u(N, vector<int>(N, 0)), d(N, vector<int>(N, 0));
		for (int i=0; i<N; ++i) {
			for (int j=0; j<N; ++j) {
				if (!g[i][j]) { continue; }
				l[i][j] = 1 + ((j > 0) ? l[i][j-1] : 0);
				u[i][j] = 1 + ((i > 0) ? u[i-1][j] : 0);
			}
		}
		for (int i=N-1; i>=0; --i) {
			for (int j=N-1; j>=0; --j) {
				if (!g[i][j]) { continue; }
				r[i][j] = 1 + ((j < N-1) ? r[i][j+1] : 0);
				d[i][j] = 1 + ((i < N-1) ? d[i+1][j] : 0);
			}
		}

		int ans = 0;
		for (int i=0; i<N; ++i) {
			for (int j=0; j<N; ++j) {
				int tmp = min(u[i][j], min(d[i][j], min(l[i][j], r[i][j])));
				ans = max(tmp, ans);
			}
		}

		return ans;
	}
};
