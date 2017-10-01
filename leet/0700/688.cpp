class Solution {
public:
	struct Item {
		int x, y, k;
	};
	double knightProbability(int N, int K, int r, int c) {
		vector<vector<vector<bool>>> vis(K+1, vector<vector<bool>>(N, vector<bool>(N, false)));
		vector<vector<vector<double>>> p(K+1, vector<vector<double>>(N, vector<double>(N, 0)));
		const int mov[8][2] = { {-1, -2}, {-2, -1}, {-2, 1}, {-1, 2}, {1, 2}, {2, 1}, {2, -1}, {1, -2} };

		vis[0][r][c] = true;
		p[0][r][c] = 1;
		queue<Item> q;
		Item tmp = { r, c, 0 };
		q.push(tmp);

		while (!q.empty()) {
			tmp = q.front(); q.pop();
			double v = p[tmp.k][tmp.x][tmp.y] / 8;
			for (int i=0; i<8; ++i) {
				int x = tmp.x + mov[i][0], y = tmp.y + mov[i][1];
				if (x < 0 || x>=N || y<0 || y>=N) { continue; }
				p[tmp.k+1][x][y] += v;
				if (!vis[tmp.k+1][x][y] && tmp.k<K-1) {
					vis[tmp.k+1][x][y] = true;
					Item tmp1 = { x, y, tmp.k+1 };
					q.push(tmp1);
				}
			}
		}

		double ans = 0;
		for (int i=0; i<N; ++i) {
			for (int j=0; j<N; ++j) {
				ans += p[K][i][j];
			}
		}

		return ans;
	}
};
