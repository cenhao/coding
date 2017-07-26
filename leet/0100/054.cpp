#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	vector<int> spiralOrder(vector<vector<int>>& matrix) {
		if (matrix.size() <= 0) {
			return vector<int>();
		}

		int h = matrix.size(), w = matrix[0].size();
		vector<int> ans;

		int x = 0, y = 0;
		int rl = w, dl = h, ll = -1, ul = 0;
		int tar = h * w;
		while (ans.size() < tar) {
			for (int i=y; i<rl && (ans.size()<tar); ++i) {
				ans.push_back(matrix[x][i]);
			}

			y = --rl; ++x;

			for (int i=x; i<dl && (ans.size()<tar); ++i) {
				ans.push_back(matrix[i][y]);
			}

			x = --dl; --y;

			for (int i=y; i>ll && (ans.size()<tar); --i) {
				ans.push_back(matrix[x][i]);
			}

			y = ++ll; --x;

			for (int i=x; i>ul && (ans.size()<tar); --i) {
				ans.push_back(matrix[i][y]);
			}

			x = ++ul; ++y;
		}

		return ans;
	}
};

int main() {
	int n, m; cin >> n >> m;
	vector<vector<int>> mat(n, vector<int>(m));
	for (int i=0; i<n; ++i) {
		for (int j=0; j<m; ++j) cin >> mat[i][j];
	}

	Solution sol;
	sol.spiralOrder(mat);
	return 0;
}
