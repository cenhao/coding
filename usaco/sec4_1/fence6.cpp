/*
ID: cenhao11
PROG: fence6
LANG: C++11
*/

#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

#define MAXN 100
#define MAXC 8
#define INF 500000

int edges[MAXN];
int nodeId[MAXN][MAXN];
int dist[MAXN+1][MAXN+1];
int floyd[MAXN+1][MAXN+1];

int main() {
	freopen("fence6.in", "r", stdin);
	freopen("fence6.out", "w", stdout);

	memset(edges, 0, sizeof(edges));
	memset(dist, 0x7f, sizeof(dist));
	memset(floyd, 0x7f, sizeof(floyd));
	int cnt = 0;

	int N; scanf("%d", &N);
	for (int i=0; i<N; ++i) {
		int s, l, n[2]; scanf("%d%d%d%d", &s, &l, &n[0], &n[1]);
		--s; edges[s] = l;
		int nid[2];
		for (int i1=0; i1<2; ++i1) {
			int processedLink = -1;
			int tmparr[MAXC];
			for (int i2=0; i2<n[i1]; ++i2) {
				scanf("%d", &tmparr[i2]);
				--tmparr[i2];
				if (edges[tmparr[i2]]) { processedLink = tmparr[i2]; }
			}

			nid[i1] = processedLink >= 0 ? nodeId[processedLink][s] : (cnt++);
			for (int i2=0; i2<n[i1]; ++i2) {
				nodeId[s][tmparr[i2]] = nodeId[tmparr[i2]][s] = nid[i1];
			}
		}

		dist[nid[0]][nid[1]] = dist[nid[1]][nid[0]] = l;
		floyd[nid[0]][nid[1]] = floyd[nid[1]][nid[0]] = l;
	}

	int mn = INF;
	for (int k=0; k<cnt; ++k) {
		for (int i=0; i<k; ++i) {
			for (int j=0; j<i; ++j) {
				if (floyd[i][j] < INF && dist[i][k] < INF && dist[j][k] < INF) {
					mn = min(floyd[i][j]+dist[i][k]+dist[j][k], mn);
				}
			}
		}
		for (int i=0; i<cnt; ++i) {
			for (int j=0; j<i; ++j) {
				if (floyd[i][k] < INF && floyd[j][k] < INF) {
					floyd[j][i] = floyd[i][j] =
						min(floyd[i][j], floyd[i][k] + floyd[j][k]);
				}
			}
		}
	}

	printf("%d\n", mn);
	return 0;
}
