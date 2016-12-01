#include <stdio.h>
#include <string.h>
#include <queue>
using namespace std;

#define MAXN 1000
#define MAXM 10000

int elink[MAXN+1];
int dist[MAXN+1];
bool vis[MAXN+1];

struct Edge {
	int v;
	int l;
	int nxt;
} edges[MAXM*2];

int efirst;

struct QueueItem {
	int v;
	int dist;
	bool operator <(const QueueItem& qi) const {
		return dist > qi.dist;
	}
};

int main() {
	int n, m, s, t;
	scanf("%d %d %d %d", &n, &m, &s, &t);
	memset(elink, -1, sizeof(elink));
	efirst = 0;

	for (int i=0; i<m; ++i) {
		int u, v, l; scanf("%d %d %d", &u, &v, &l);
		edges[efirst].v = u; edges[efirst].l = l;
		edges[efirst].nxt = elink[v];
		elink[v] = efirst++;

		edges[efirst].v = v; edges[efirst].l = l;
		edges[efirst].nxt = elink[u];
		elink[u] = efirst++;
	}

	priority_queue<QueueItem> pq;
	QueueItem item = { s, 0 };
	pq.push(item);
	memset(vis, 0, sizeof(vis));
	memset(dist, 0x7f, sizeof(dist));
	dist[s] = 0;

	while (!vis[t]) {
		item = pq.top();
		pq.pop();
		vis[item.v] = true;

		for (int cur=elink[item.v]; cur!=-1; cur=edges[cur].nxt) {
			int v = edges[cur].v;
			if (vis[v]) { continue; }
			if (dist[item.v] + edges[cur].l < dist[v]) {
				dist[v] = dist[item.v] + edges[cur].l;
				QueueItem tmp = { v, dist[v] };
				pq.push(tmp);
			}
		}
	}

	printf("%d\n", dist[t]);
	return 0;
}

