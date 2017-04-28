#include <bits/stdc++.h>
using namespace std;

#define MAXS 20
#define MAXN 1000

struct Star {
	int x, y;
} cons[MAXS][MAXS];
int size[MAXS];

char buff[MAXN];
char sky[MAXN][MAXN+1];

int main() {
	int n; scanf("%d", &n);
	for (int i=0; i<n; ++i) {
		size[i] = 0;
		int h, w; scanf("%d %d", &h, &w);
		for (int j=0; j<h; ++j) {
			scanf("%s", buff);
			for (int k=0; k<w; ++k) {
				if (buff[k] != '#') { continue; }
				cons[i][size[i]].x = j; cons[i][size[i]].y = k;
				++size[i];
			}
		}
	}

	int h, w; scanf("%d %d", &h, &w);
	for (int i=0; i<h; ++i) { scanf("%s", sky[i]); }

	for (int k=0; k<n; ++k) {
		bool found = false;
		for (int i=0; i<h && !found; ++i) {
			for (int j=0; j<w && !found; ++j) {
				if (sky[i][j] != '#') { continue; }
				found = true;
				for (int ii=1; ii<size[k]; ++ii) {
					if (sky[i+cons[k][ii].x-cons[k][0].x][j+cons[k][ii].y-cons[k][0].y] != '#') {
						found = false;
						break;
					}
				}
			}
		}

		printf(found ? "Yes\n" : "No\n");
	}

	return 0;
}
