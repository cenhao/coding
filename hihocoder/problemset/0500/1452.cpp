#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

#define MAXW 100000
#define MAXS 100000
#define MAXL 128
#define ROOT 0

char w[MAXW+1];
char s[MAXS+1];

struct TrieNode {
	bool full;
	int links[MAXL];
	int nxt;
	int depth;
} nodes[MAXW+1];
int nfirst;

void init() {
	memset(nodes, 0, sizeof(nodes));
	nfirst = 1;
}

void insert(char *w) {
	int cur = ROOT;
	for (int i=0, end=strlen(w); i<end; ++i) {
		if (nodes[cur].links[w[i]] == 0) {
			nodes[cur].links[w[i]] = nfirst++;
		}

		cur = nodes[cur].links[w[i]];
		nodes[cur].depth = i + 1;
	}

	nodes[cur].full = true;
}

int links[MAXL];

int main() {
	init();
	int n; scanf("%d", &n);
	for (int i=0; i<n; ++i) {
		scanf("%s", w);
		insert(w);
	}

	memset(links, -1, sizeof(links));
	for (int i=0; i<MAXL; ++i) {
		if (nodes[ROOT].links[i] > 0) {
			int idx = nodes[ROOT].links[i];
			nodes[idx].nxt = links[i];
			links[i] = idx;
		}
	}

	int mx = 0;
	scanf("%s", s);
	for (int i=0, end=strlen(s); i<end; ++i) {
		if (links[s[i]] <= 0) { continue; }
		int cur = links[s[i]]; links[s[i]] = -1;
		for (int j=cur; j!=-1; j=nodes[j].nxt) {
			if (nodes[j].full) { mx = max(mx, nodes[j].depth); }

			for (int k=0; k<MAXL; ++k) {
				if (nodes[j].links[k] <= 0) { continue; }
				int idx = nodes[j].links[k];
				nodes[idx].nxt = links[k];
				links[k] = idx;
			}
		}
	}

	printf("%d\n", mx);

	return 0;
}
