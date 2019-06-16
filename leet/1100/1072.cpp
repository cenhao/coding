#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int check(vector<vector<int>> &m, vector<bool> &f, vector<bool> &chk) {
		int rsz = m.size(), csz = m[0].size();
		int cnt = 0;
		for (int i=0; i<rsz; ++i) {
			int v = 2;
			bool ok = true;
			for (int j=0; j<csz && ok; ++j) {
				int vv = m[i][j] ^ (f[j] ? 1 : 0);
				if (v!=2 && vv!=v) { ok = false;; }
				v = vv;
			}

			if (ok) {
				++cnt;
				chk[i] = true;
			}
		}

		return cnt;
	}

	int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
		int rsz = matrix.size(), csz = matrix[0].size();
		vector<bool> flip(csz, false);
		vector<bool> chk(rsz, false);
		int mx = 0;
		for (int i=0; i<rsz; ++i) {
			if (chk[i]) { continue; }
			for (int j=0; j<csz; ++j) {
				flip[j] = matrix[i][j] == 0;
			}

			mx = max(check(matrix, flip, chk), mx);
		}

		return mx;
	}
};

int main() {
	int n, m; cin >> n >> m;
	vector<vector<int>> mat(n, vector<int>(m));
	for (int i=0; i<n; ++i) {
		for (int j=0; j<m; ++j) cin >> mat[i][j];
	}

	Solution sol;
	cout << sol.maxEqualRowsAfterFlips(mat) << endl;
	return 0;
}
