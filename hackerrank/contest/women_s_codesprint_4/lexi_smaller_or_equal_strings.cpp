#include <bits/stdc++.h>
using namespace std;

#define MAXN 100000
#define MAXL 15

char strs[MAXN][MAXL+1], qstr[MAXN][MAXL+1];
int ans[MAXN], tfirst = 1;
struct TrieNode {
	int cnt, ccnt;
	int lnk[26];
} tn[MAXN*MAXL+10];
struct Query {
	int p, id;
} qry[MAXN*2];

void insert_str(int id) {
	++tn[0].cnt;
	int cur = 0;
	for (int i=0, len=strlen(strs[id]); i<len; ++i) {
		int idx = strs[id][i] - 'a';
		if (tn[cur].lnk[idx] == -1) {
			memset(tn[tfirst].lnk, -1, sizeof(tn[tfirst].lnk));
			tn[tfirst].cnt = tn[tfirst].ccnt = 0;
			tn[cur].lnk[idx] = tfirst++;
		}
		cur = tn[cur].lnk[idx];
		++tn[cur].cnt;
	}

	++tn[cur].ccnt;
}

int check(int id) {
	int ret = 0, cur = 0;
	for (int i=0, len=strlen(qstr[id]); i<len && cur>=0; ++i) {
		ret += tn[cur].ccnt;
		int idx = qstr[id][i] - 'a';
		for (int j=0, tidx; j<idx; ++j) {
			if ((tidx=tn[cur].lnk[j]) >= 0) { ret += tn[tidx].cnt; }
		}
		cur = tn[cur].lnk[idx];
	}

	if (cur >= 0) { ret += tn[cur].ccnt; }
	return ret;
}

int main() {
	int n; scanf("%d", &n);
	for (int i=0; i<n; ++i) { scanf("%s", strs[i]); }
	int q; scanf("%d", &q);
	for (int i=0; i<q; ++i) {
		int l, r; scanf("%d%d %s", &l, &r, qstr[i]);
		qry[i*2] = { l-2, -(i+1) };
		qry[i*2+1] = { r-1, i+1 };
	}
	sort(qry, qry+q*2, [](const Query &q1, const Query &q2) {
		return (q1.p != q2.p) ? q1.p < q2.p : q1.id < q2.id;
	});

	memset(tn[0].lnk, -1, sizeof(tn[0].lnk));
	tn[0].cnt = 0;

	for (int i=0, end=q*2, ni=0; i<end; ++i) {
		while (ni <= qry[i].p) { insert_str(ni++); }
		int id = abs(qry[i].id)-1;
		int sm = check(id);
		if (qry[i].id < 0) {
			ans[id] = -sm;
		} else {
			ans[id] += sm;
		}
	}

	for (int i=0; i<q; ++i) { printf("%d\n", ans[i]); }
	return 0;
}
