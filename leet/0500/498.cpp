#include <iostream>
#include <vector>
using namespace std;

class Solution {
	public:
	bool co(int v, int l, int r) {
		return (v >= l && v < r);
	}

	vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
		int n = matrix.size();
		if (n <= 0) {
			return vector<int>();
		}
		int m = matrix[0].size();

		vector<int> ans(n*m);
		const int move[2][2] = { {-1, 1}, {1, -1} };

		int cnt = 0, end = n * m;
		int cur = 0;
		int xs = 1, ys = -1;
		while (cnt < end) {
			while (co(xs+move[cur][0], 0, n) && co(ys+move[cur][1], 0, m)) {
				xs += move[cur][0]; ys += move[cur][1];
				ans[cnt++] = matrix[xs][ys];
			}

			if (cur == 0) {
				if (ys + 1 < m) {
					++ys;
				} else {
					++xs;
				}
			} else {
				if (xs + 1 < n) {
					++xs;
				} else {
					++ys;
				}
			}

			cur = (cur + 1) & 1;
			xs -= move[cur][0]; ys -= move[cur][1];
		}

		return ans;
	}
};

int main() {
	int a = 2, b = 3;
	vector<vector<int>> m(a, vector<int>(b));
	for (int i=0; i<m.size(); ++i) {
		for (int j=0; j<m[i].size(); ++j) {
			m[i][j] = i*b + j + 1;
		}
	}

	Solution sol;
	vector<int> ans = sol.findDiagonalOrder(m);
	for (int i=0; i<ans.size(); ++i) {
		cout << ans[i] << endl;
	}

	return 0;
}
