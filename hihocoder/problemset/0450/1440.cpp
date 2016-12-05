#include <algorithm>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

#define MAXN 1000
#define MAXW 100000
#define MAXS 100000
#define MAXC 26

char str[MAXS+1];
char keyword[MAXS+1];

const int root = 0;

struct TrieGraphNode {
	int depth;
	int fail;
	int complete;
	int links[MAXC];
} nodes[MAXW+1];
int nfirst;

struct QueueItem {
	int edge;
	int parent;
	int cur;
};

queue<QueueItem> q;

void init() {
	memset(nodes, 0, sizeof(nodes));
	nfirst = 1;
}

void insert(char *w, int widx, int cur) {
	if (w[widx] == 0) {
		nodes[cur].complete = cur;
		return;
	}

	int idx = w[widx] - 'a';
	if (nodes[cur].links[idx] == 0) {
		nodes[nfirst].depth = nodes[cur].depth + 1;
		nodes[cur].links[idx] = nfirst++;
	}

	insert(w, widx+1, nodes[cur].links[idx]);
}

void build(int edge, int parent, int cur) {
	int pf = nodes[parent].fail, fail = 0;
	if (parent != 0) {
		while (pf != root && nodes[pf].links[edge] <= 0) {
			pf = nodes[pf].fail;
		}

		if (nodes[pf].links[edge] > 0) {
			fail = nodes[cur].fail = nodes[pf].links[edge];
		}

		if (nodes[cur].complete == 0) {
			nodes[cur].complete = nodes[fail].complete;
		}
	}

	QueueItem item = {0, cur, 0};
	for (int i=0; i<MAXC; ++i) {
		if (nodes[cur].links[i] <= 0) {
			nodes[cur].links[i] = -abs(nodes[fail].links[i]);
		} else {
			item.edge = i; item.cur = nodes[cur].links[i];
			q.push(item);
		}
	}
}

void build() {
	for (int i=0; i<MAXC; ++i) {
		if (nodes[root].links[i] <= 0) { continue; }
		QueueItem item = { i, root, nodes[root].links[i] };
		q.push(item);
	}

	while (!q.empty()) {
		QueueItem item = q.front();
		q.pop();
		build(item.edge, item.parent, item.cur);
	}
}

void match() {
	int start=-1, end=-1;
	int cur = root;
	for (int i=0, len=strlen(str); i<len; ++i) {
		cur = abs(nodes[cur].links[str[i]-'a']);
		if (nodes[cur].complete > 0) {
			int ts = i - nodes[nodes[cur].complete].depth + 1;
			int te = i;

			if (ts < start) {
				for (int j=ts; j<start; ++j) { str[j] = '*'; }
				for (int j=end+1; j<=te; ++j) { str[j] = '*'; }
				start = ts; end = te;
			} else if (ts <= end) {
				for (int j=end+1; j<=te; ++j) { str[j] = '*'; }
				end = te;
			} else {
				for (int j=ts; j<=te; ++j) { str[j] = '*'; }
				start = ts; end = te;
			}
		}
	}
}

int main() {
	init();
	int n; scanf("%d", &n);
	for (int i=0; i<n; ++i) {
		scanf("%s", keyword);
		insert(keyword, 0, 0);
	}
	build();

	scanf("%s", str);
	match();
	printf("%s\n", str);

	return 0;
}
