#include <bits/stdc++.h>
using namespace std;

#define MAXN 100000
int first[1 << 10];
int ccnt[MAXN+1][10];

void process(const vector<vector<int>> &mat, int &x0, int &y0, int &x1, int &y1) {
	int rsz = mat.size(), csz = mat[0].size();
	vector<vector<int>> status(rsz+1, vector<int>(csz+1, 0));
	vector<vector<vector<int>>> cnt(rsz+1, vector<vector<int>>(csz+1, vector<int>(10, 0)));

	for (int i=0; i<rsz; ++i) {
		int ii = i + 1;
		for (int j=0; j<csz; ++j) {
			int jj = j + 1;
			status[ii][jj] = (1<<mat[i][j]) ^ status[i][j] ^ status[ii][j] ^ status[i][jj];
			for (int k=0; k<10; ++k) { cnt[ii][jj][k] = cnt[ii][j][k] + cnt[i][jj][k] - cnt[i][j][k]; }
			++cnt[ii][jj][mat[i][j]];
		}
	}

	memset(ccnt[0], 0, sizeof(ccnt));
	int mx = 0;
	for (int i=0; i<rsz; ++i) {
		int ii = i + 1;
		for (int k=0; k<ii; ++k) {
			memset(first, -1, sizeof(first));
			for (int j=0; j<csz; ++j) {
				int jj = j + 1;
				int cs = status[ii][jj] ^ status[k][jj];
				if (first[cs] == -1) { first[cs] = jj; }
				for (int l=0; l<10; ++l) { ccnt[jj][l] = cnt[ii][jj][l] - cnt[k][jj][l]; }
				int mn = MAXN + 100;
				for (int l=-1; l<10 && mn > 0; ++l) {
					int mask = (l == -1) ? 0 : (1 << l);
					int pos = 0;
					if (cs != mask) {
						int need = cs ^ mask;
						if ((pos=first[need]) == -1) { continue; }
					}
					if (ccnt[jj][0]-ccnt[pos][0] > 1) {
						bool ok = false;
						for (int b=1; b<10; ++b) {
							if (ccnt[jj][b] - ccnt[pos][b] > 1) {
								ok = true;
								break;
							}
						}

						if (!ok) { continue; }
					}

					mn = min(pos, mn);
				}

				if (mn > MAXN) { continue; }
				int sz = (ii-k) * (jj-mn);
				if (sz > mx) {
					mx = sz;
					x0 = k; x1 = i;
					y0 = mn; y1 = j;
				}
			}
		}
	}
}

int main() {
	int n, m; scanf("%d%d", &n, &m);
	vector<vector<int>> mat(n, vector<int>(m));
	for (int i=0; i<n; ++i) {
		for (int j=0; j<m; ++j) {
			int v; scanf("%d", &v);
			mat[i][j] = v;
		}
	}

	int x[2], y[2];
	if (n <= m) {
		process(mat, x[0], y[0], x[1], y[1]);
	} else {
		vector<vector<int>> mat_t(m, vector<int>(n));
		for (int i=0; i<n; ++i) {
			for (int j=0; j<m; ++j) { mat_t[j][i] = mat[i][j]; }
		}
		process(mat_t, y[0], x[0], y[1], x[1]);
	}

	int sz = (x[1] - x[0] + 1) * (y[1] - y[0] + 1);
	printf("%d\n", sz);
	printf("%d %d %d %d\n", x[0], y[0], x[1], y[1]);
	return 0;
}
