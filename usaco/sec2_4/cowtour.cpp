/*
ID: cenhao11
PROG: cowtour
LANG: C++11
*/

/*
 * The problem description is a bit obscure. In short, there can be more than
 * two fields, but you are only required to connect two of them.
 * Use floyd to calculate the shortest path length within each field.
 * Let the longest distance between two pastures within field a to be La
 * then for field b this would be Lb.
 * Let the longest distance from pasture x to any pasture within a field to be
 * Xa
 * The diameter of the connected two fields a & b is:
 * min(La, Lb, min(Xa + dist(x, y) + Yb))
 * I made a mistake that I though Xa always equals La, so that I though
 * min(Xa + dist(x, y) + Yb) > La or Lb. <<<< This is wrong
 */

#include <math.h>
#include <stdio.h>
#include <string.h>

#define MAXN 150
#define ESP 1e-8
#define INF 1e13

int pasture[MAXN][2];
int mark[MAXN];
int sets[MAXN][MAXN+1];
double dist[MAXN][MAXN];
double mx[MAXN];
double fmx[MAXN];

void dfs(int cur, int end, int n) {
	mark[cur] = n;
	for (int i=0; i<end; ++i) {
		if (cur != i && dist[cur][i] < INF && mark[i] < 0) {
			dfs(i, end, n);
		}
	}
}

int main() {
	freopen("cowtour.in", "r", stdin);
	freopen("cowtour.out", "w", stdout);
	int n;
	scanf("%d", &n);
	for (int i=0; i<n; ++i) {
		scanf("%d%d", &pasture[i][0], &pasture[i][1]);
	}
	for (int i=0; i<n; ++i) {
		char buff[MAXN + 10];
		scanf("%s", buff);
		for (int j=0; j<n; ++j) {
			if (i == j) {
				dist[i][j] = 0.0;
			}
			else if (buff[j] == '0') {
				dist[i][j] = INF;
			} else {
				double x = pasture[i][0] - pasture[j][0];
				double y = pasture[i][1] - pasture[j][1];
				dist[i][j] = sqrt(x*x + y*y);
			}
		}
	}

	for (int k=0; k<n; ++k) {
		for (int i=0; i<n; ++i) {
			for (int j=0; j<n; ++j) {
				double newdist = dist[i][k] + dist[k][j];
				if (newdist + ESP < dist[i][j]) {
					dist[i][j] = newdist;
				}
			}
		}
	}

	for (int i=0; i<n; ++i) {
		mx[i] = 0;
		for (int j=0; j<n; ++j) {
			if (dist[i][j] < INF && dist[i][j] > mx[i] + ESP) {
				mx[i] = dist[i][j];
			}
		}
	}

	memset(mark, -1, sizeof(mark));
	int fcnt = 0;
	for (int i=0; i<n; ++i) {
		if (mark[i] < 0) {
			dfs(i, n, fcnt++);
		}
	}

	memset(sets, 0, sizeof(sets));
	memset(fmx, 0, sizeof(fmx));
	for (int i=0; i<n; ++i) {
		int idx = mark[i];
		sets[idx][++sets[idx][0]] = i;
		if (mx[i] > fmx[idx] + ESP) { fmx[idx] = mx[i]; }
	}

	double res = INF;
	for (int i=0; i<fcnt; ++i) {
		for (int j=i+1; j<fcnt; ++j) {
			double d = (fmx[i] > fmx[j] + ESP) ? fmx[i] : fmx[j];
			for (int k=1; k<=sets[i][0]; ++k) {
				for (int l=1; l<=sets[j][0]; ++l) {
					double x = pasture[sets[i][k]][0] - pasture[sets[j][l]][0];
					double y = pasture[sets[i][k]][1] - pasture[sets[j][l]][1];
					double cost = sqrt(x*x + y*y) + mx[sets[i][k]] + mx[sets[j][l]];
					if (d > cost + ESP) { cost = d; }
					if (cost + ESP < res) { res = cost; }
				}
			}
		}
	}

	printf("%.6lf\n", res);
	return 0;
}
