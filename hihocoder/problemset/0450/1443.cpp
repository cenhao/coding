#include <algorithm>
#include <cstdio>
using namespace std;

#define MAXN 8

bool vis[MAXN];
char output[MAXN*2+1];

void dfs(bool isDash, int cur, int last, int depth, int stop) {
	if (depth >= stop) {
		output[cur] = 0;
		printf("%s\n", output);
		return ;
	}

	if (!isDash) {
		output[cur] = '-';
		dfs(true, cur+1, -1, depth, stop);
	}
	for (int i=0; i<stop; ++i) {
		if (vis[i]) { continue; }
		vis[i] = true;
		if (i > last) {
			output[cur] = '1' + i;
			dfs(false, cur+1, i, depth+1, stop);
		}
		vis[i] = false;
	}
}

int main() {
	int n; scanf("%d", &n);
	dfs(true, 0, -1, 0, n);
	return 0;
}
