#include <bits/stdc++.h>
using namespace std;

#define MAXN 100000
#define INF (MAXN+10)

struct Edge {
	int v, nxt;
} e[MAXN+1];

int adj[MAXN+1];
// 0: not sent, self might be burned out
// 1: not sent, self is not burned out
// 2: sent
// all sub tree is clean
int dp[MAXN+1][3];
bool nf[MAXN+1]; // need to go to the conference

void dfs(int cur) {
	for (int i=adj[cur]; i!=-1; i=e[i].nxt) {
		dfs(e[i].v);
	}

	int sum_for_0 = 0;
	int sum_for_2 = 0;
	int sum_mn_12 = 0;
	int mn = INF;
	for (int i=adj[cur]; i!=-1; i=e[i].nxt) {
		int v = e[i].v;
		// for 2, cur is going to be sent, so pick the one with lowest cost
		sum_for_2 += min(min(dp[v][0], dp[v][1]), dp[v][2]);

		// for 0, cur has to be burned, then its children must not be sent
		sum_for_0 = min(sum_for_0+dp[v][1], INF);

		// for 1, we won't send cur, then all the children has to be healthy
		int mn_12 = min(dp[v][1], dp[v][2]);
		sum_mn_12 += mn_12;
		// but as for cur to be healthy, at least one children has to be sent, find the one with minimum cost
		mn = min(mn, dp[v][2]-mn_12);
	}

	// if cur is healthy, then set it to INF to mean inpossible
	dp[cur][0] = (nf[cur]) ? sum_for_0 : INF;
	// if cur is burned, then at least one children has to be sent so as to make cur healthy
	dp[cur][1] = min(sum_mn_12 + (nf[cur] ? mn : 0), INF);
	dp[cur][2] = sum_for_2 + 1;
}

int main() {
	memset(adj, -1, sizeof(adj));

	int n; scanf("%d", &n);
	for (int i=1; i<n; ++i) {
		int s, nb; scanf("%d %d", &s, &nb);
		nf[i] = (nb == 0);
		e[i] = { i, adj[s] }; adj[s] = i;
	}
	nf[0] = false;

	dfs(0);
	int mn = min(dp[0][1], dp[0][2]);
	printf("%d\n", mn);
	return 0;
}
