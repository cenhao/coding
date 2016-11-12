#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <string>
#include <unordered_map>
using namespace std;

#define MAXN 100000
#define MAXL 20
#define EPS 10e-6

struct Link {
	int cid;
	int nxt;
} links[MAXN];
int lfirst;

string names[MAXN+1];
int idx[MAXN+1];
int children[MAXN+1];
int first;

int depth[20][MAXN*2+2];
int nid[20][MAXN*2+2];
int rfirst;

char name[2][1024];
unordered_map<string, int> namemap;

void dfs(int p, int d) {
	for (int cur=children[p]; cur!=-1; cur=links[cur].nxt) {
		dfs(links[cur].cid, d+1);
		nid[0][rfirst] = p;
		depth[0][rfirst++] = d;
	}

	nid[0][rfirst] = p;
	depth[0][rfirst] = d;
	idx[p] = rfirst++;
}

void prermq() {
	for (int pw=1, pwend=int(log2(rfirst)); pw<=pwend; ++pw) {
		int len = 1 << pw;
		int sub = len >> 1;
		for (int i=0, end=rfirst-len; i<=end; ++i) {
			if (depth[pw-1][i] < depth[pw-1][i+sub]) {
				depth[pw][i] = depth[pw-1][i];
				nid[pw][i] = nid[pw-1][i];
			} else {
				depth[pw][i] = depth[pw-1][i+sub];
				nid[pw][i] = nid[pw-1][i+sub];
			}
		}
	}
}

void init() {
	memset(children, -1, sizeof(children));

	int n; scanf("%d", &n);
	for (int i=0; i<n; ++i) {
		scanf("%s %s", name[0], name[1]);
		string sname1(name[0]);
		string sname2(name[1]);

		auto it = namemap.find(sname1);
		if (it == namemap.end()) {
			it = namemap.insert(pair<string, int>(sname1, first)).first;
			names[first++] = move(sname1);
		}
		int cid1 = it->second;

		it = namemap.find(sname2);
		if (it == namemap.end()) {
			it = namemap.insert(pair<string, int>(sname2, first)).first;
			names[first++] = move(sname2);
		}
		int cid2 = it->second;
		
		links[lfirst].cid = cid2;
		links[lfirst].nxt = children[cid1];
		children[cid1] = lfirst++;
	}

	dfs(0, 0);
	prermq();
}

void query() {
	int m; scanf("%d", &m);
	for (int i=0; i<m; ++i) {
		scanf("%s %s", name[0], name[1]);
		string sname1 = name[0];
		string sname2 = name[1];

		int cid1 = namemap[sname1];
		int cid2 = namemap[sname2];
		int idx1 = min(idx[cid1], idx[cid2]);
		int idx2 = max(idx[cid1], idx[cid2]);

		int pw = int(log2(idx2-idx1+1) + EPS);
		int len = 1 << pw;
		int mcid;

		if (depth[pw][idx1] < depth[pw][idx2-len+1]) {
			mcid = nid[pw][idx1];
		} else {
			mcid = nid[pw][idx2-len+1];
		}

		printf("%s\n", names[mcid].c_str());
	}
}

int main() {
	init();
	query();
	return 0;
}
