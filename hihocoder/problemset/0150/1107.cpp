#include <bits/stdc++.h>
using namespace std;

#define MAXL 2000000

char buff[MAXL+1];

struct Node {
	int lnk[26];
	int cnt;
} nod[MAXL+1];
int nfirst = 1;

int insert(char *query) {
	int len = strlen(query);
	int cur = 0;
	for (int i=0; i<len; ++i) {
		++nod[cur].cnt;
		int idx = query[i] - 'a';
		if (nod[cur].lnk[idx] == -1) {
			nod[cur].lnk[idx] = nfirst;
			nod[nfirst].cnt = 0;
			memset(nod[nfirst].lnk, -1, sizeof(nod[nfirst].lnk));
			++nfirst;
		}

		cur = nod[cur].lnk[idx];
	}

	++nod[cur].cnt;
}

int dfs(int cur, int pre) {
	if (pre > 5 && nod[cur].cnt <= 5) { return 1; }
	int ans = 0;
	for (int i=0; i<26; ++i) {
		if (nod[cur].lnk[i] != -1) { ans += dfs(nod[cur].lnk[i], nod[cur].cnt); }
	}

	return ans;
}

int main() {
	memset(nod[0].lnk, -1, sizeof(nod[0].lnk));
	nod[0].cnt = 0;

	int n; scanf("%d", &n);
	for (int i=0; i<n; ++i) {
		scanf("%s", buff);
		insert(buff);
	}

	int ans = dfs(0, 0);
	printf("%d\n", ans);
	return 0;
}
