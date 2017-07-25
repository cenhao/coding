#include <bits/stdc++.h>
using namespace std;

#define MAXN 50
#define MAXH 100
#define MAXW 800

char pattern[MAXN][MAXN+1];
char pic[MAXH][MAXW+1];

int main() {
	int n, m, t; scanf("%d%d%d", &n, &m, &t);
	for (int i=0; i<n; ++i) { scanf("%s", pattern[i]); }
	while (t--) {
		int h, w; scanf("%d%d", &h, &w);
		for (int i=0; i<h; ++i) { scanf("%s", pic[i]); }
		bool valid = true;

		// the picture should have a repeating pattern
		for (int i=0; i<h && valid; ++i) {
			for (int j=m; j<w && valid; ++j) {
				valid = (pic[i][j] == pic[i][j-m] && (i<n || pic[i][j] == pic[i-n][j]));
			}
		}

		if (valid) {
			bool found = false;
			for (int i=0; i<n && !found; ++i) {
				for (int j=0; j<m && !found; ++j) {
					bool match = true;
					// only need to check a small portion
					for (int x=0; x<min(n, h) && match; ++x) {
						int nx = (i + x) % n;
						for (int y=0; y<min(m, w) && match; ++y) {
							int ny = (j + y) % m;
							match = pic[x][y] == pattern[nx][ny];
						}

					}

					found = match;
				}
			}

			valid = found;
		}

		printf(valid ? "YES\n" : "NO\n");
	}

	return 0;
}
