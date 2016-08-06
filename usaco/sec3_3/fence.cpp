/*
ID: cenhao11
PROG: fence
LANG: C++11
*/

/*
 * Finding a eulerian path in an undirected graph.
 * The problem is to find the smallest one.
 * Given the nature of the algorithm, the vertex which
 * get visited eariler are added later, so if we pick the
 * smaller vertex, then we have a path that have the smallest
 * vertex at the end. Then reverse the path, we have a path with
 * smallest vertex at the beginning.
 *
 * Originally I pick the largest vertex, so that I have a path
 * that the largest vertex at the end. However, this does not guarantee
 * the smallest is at the beginning.
 */

#include <stdio.h>
#include <string.h>

#define MAXN 500
#define MAXF 1024

int edges[MAXN+1][MAXN+1];
int ecnt[MAXN+1];
int path[MAXF+1];
int pos = 0;
int mx = 0;

void find(int start) {
	for (int i=ecnt[start]; i<=mx; ++i) {
		if (edges[start][i] > 0) {
			--edges[start][i];
			--edges[i][start];
			ecnt[start] = i;
			find(i);
		}
	}

	path[pos++] = start;
}

int main() {
	freopen("fence.in", "r", stdin);
	freopen("fence.out", "w", stdout);

	memset(edges, 0, sizeof(edges));
	memset(ecnt, 0, sizeof(ecnt));

	int f;
	scanf("%d", &f);

	for (int i=0; i<f; ++i) {
		int a, b;
		scanf("%d%d", &a, &b);
		if (a > mx) { mx = a; }
		if (b > mx) { mx = b; }
		++edges[a][b];
		++edges[b][a];
		++ecnt[a];
		++ecnt[b];
	}

	int start = 1;
	for (int i=mx; i>0; --i) {
		if (ecnt[i] & 1) {
			start = i;
		}
		ecnt[i] = 1;
	}

	find(start);

	for (int i=f; i>=0; --i) {
		printf("%d\n", path[i]);
	}

	return 0;
}
