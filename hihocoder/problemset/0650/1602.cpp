#include <bits/stdc++.h>
using namespace std;

#define MAXS 800000

char in[MAXS+1];

struct PTN {
	int lnk[26];
	int fail, len;
} nodes[MAXS+2];
int pfirst;

void init() {
	memset(nodes[0].lnk, -1, sizeof(nodes[0].lnk));
	memset(nodes[1].lnk, -1, sizeof(nodes[1].lnk));
	nodes[0].fail = nodes[1].fail = 0;
	nodes[0].len = -1; nodes[1].len = 0;
	pfirst = 2;
}

int insert(int cur, int pos) {
	char c = in[pos];
	int idx = c - 'a';

	while (cur != 0 && (pos-nodes[cur].len-1 < 0 || in[pos-nodes[cur].len-1] != c)) {
		cur = nodes[cur].fail;
	}

	if (nodes[cur].lnk[idx] != -1) { return nodes[cur].lnk[idx]; }
	int nxt = nodes[cur].lnk[idx] = pfirst++;
	memset(nodes[nxt].lnk, -1, sizeof(nodes[nxt].lnk));
	nodes[nxt].len = nodes[cur].len + 2;

	int fail = nodes[cur].fail;
	while (fail != 0 && (pos-nodes[fail].len-1 < 0 || in[pos-nodes[fail].len-1] != c)) {
		fail = nodes[fail].fail;
	}

	nodes[nxt].fail = nodes[fail].lnk[idx] == nxt ? 1 : nodes[fail].lnk[idx];
	return nxt;
}

int main() {
	scanf("%s", in);
	int len = strlen(in);
	init();
	for (int i=0, cur=0; i<len; ++i) {
		cur = insert(cur, i);
	}

	printf("%d\n", pfirst-2);
	return 0;
}
