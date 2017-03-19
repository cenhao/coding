#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	struct Pos {
		int x, y;
	};

	vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
		const int mov[4][2] = { {0, 1}, {1, 0}, {-1, 0}, {0, -1} };
		int n = matrix.size(), m = matrix[0].size();
		queue<Pos> q;
		vector<vector<int>> res(matrix.size(), vector<int>(matrix[0].size(), -1));
		Pos tmp;

		for (int i=0; i<matrix.size(); ++i) {
			for (int j=0; j<matrix[0].size(); ++j) {
				if (matrix[i][j] == 0) {
					res[i][j] = 0;
					tmp.x = i; tmp.y = j;
					q.push(tmp);
				}
			}
		}

		while (!q.empty()) {
			tmp = q.front(); q.pop();
			for (int i=0; i<4; ++i) {
				Pos tmp1 = {tmp.x + mov[i][0], tmp.y + mov[i][1]};
				if (tmp1.x < 0 || tmp1.x >= n ||
					tmp1.y < 0 || tmp1.y >= m ||
					res[tmp1.x][tmp1.y] != -1) {
					continue;
				}

				res[tmp1.x][tmp1.y] = res[tmp.x][tmp.y] + 1;
				q.push(tmp1);
			}
		}

		return res;
	}
};
