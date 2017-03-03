#include <algorithm>
#include <cinttypes>
#include <cstdint>
#include <cstdio>
#include <cstring>
#include <queue>
#include <string>
#include <vector>
using namespace std;

#define MAXN 100000
#define MAXS 2000000
#define RNG 26
#define PATTERN 0x1
#define QUERY 0x2

char buff[MAXS+1];
int health[MAXN+1];
int gene_idx[MAXN+1];
int enter[MAXS+1], ext[MAXS+1];

struct TrieNode {
	int fail, type;
	int child, sibling;
	int links[RNG];
} nodes[MAXS+1];
int nfirst = 0;

int get_next_node() {
	int ret = nfirst++;
	memset(nodes[ret].links, 0, sizeof(nodes[ret].links));
	nodes[ret].fail = nodes[ret].type = 0;
	nodes[ret].child = nodes[ret].sibling = -1;
	return ret;
}

int insert(char *str, int type) {
	int cur = 0; // root
	for (int i=0; str[i]!=0; ++i) {
		int l = str[i] - 'a';
		if (nodes[cur].links[l] == 0) { nodes[cur].links[l] = get_next_node(); }
		cur = nodes[cur].links[l];
	}

	nodes[cur].type |= type;
	return cur;
}

void build_suffix_nodes(int par, int child) {
	nodes[child].sibling = nodes[par].child;
	nodes[par].child = child;
}

void build_trie_graph() {
	int idx;
	queue<int> q;
	for (int i=0; i<RNG; ++i) {
		if ((idx = nodes[0].links[i]) != 0) {
			nodes[idx].fail = 0;
			q.push(idx);
			build_suffix_nodes(0, idx);
		}
	}

	while (!q.empty()) {
		int cur = q.front(); q.pop();
		for (int i=0; i<RNG; ++i) {
			int idx;
			if ((idx=nodes[cur].links[i]) != 0) {
				int fp = nodes[cur].fail;
				while (fp != 0 && nodes[fp].links[i] <= 0) {
					fp = nodes[fp].fail;
				}

				if (nodes[fp].links[i] > 0) { fp = nodes[fp].links[i]; }
				nodes[idx].fail = fp;
				nodes[idx].type |= nodes[fp].type;
				q.push(idx);
				build_suffix_nodes(fp, idx);
			}
		}
	}
}

int dfs(int cur = 0, int tick = 0) {
	if (nodes[cur].type & PATTERN) { enter[cur] = ++tick; }

	for (int i=nodes[cur].child; i>=0; i=nodes[i].sibling) {
		tick = dfs(i, tick);
	}

	return ext[cur] = tick;
}

string queries[MAXN+1];
vector<int> L[MAXN+1], R[MAXN+1];
int64_t bits[MAXS+1];
int64_t gh[MAXN+1];

void update(int idx, int val, int mx_idx) {
	while (idx <= mx_idx) {
		bits[idx] += val;
		idx += idx & (~(idx-1));
	}
}

int64_t query(int idx) {
	int64_t sum = 0;
	while (idx > 0) {
		sum += bits[idx];
		idx -= idx & (~(idx-1));
	}

	return sum;
}

int main() {
	memset(bits, 0, sizeof(bits));
	int n; scanf("%d", &n);
	get_next_node(); // root
	for (int i=0; i<n; ++i) {
		scanf("%s", buff);
		gene_idx[i] = insert(buff, PATTERN);
	}
	for (int i=0; i<n; ++i) { scanf("%d", &health[i]); }

	int s; scanf("%d", &s);
	for (int i=0; i<s; ++i) {
		int l, r; scanf("%d %d %s", &l, &r, buff);
		queries[i] = buff;
		insert(buff, QUERY);
		if (l > 0) { L[l-1].push_back(i); }
		R[r].push_back(i);
	}

	build_trie_graph();
	int mx_tick = dfs();
	memset(gh, 0, sizeof(gh));

	for (int i=0; i<n; ++i) {
		update(enter[gene_idx[i]], health[i], mx_tick);
		update(ext[gene_idx[i]]+1, -health[i], mx_tick);

		for (auto idx : L[i]) {
			int cur = 0, pos = 0;
			while (pos < queries[idx].length()) {
				cur = nodes[cur].links[queries[idx][pos++]-'a'];
				if (!(nodes[cur].type & PATTERN)) { continue; }
				gh[idx] -= query(enter[cur]);
			}
		}

		for (auto idx : R[i]) {
			int cur = 0, pos = 0;
			while (pos < queries[idx].length()) {
				cur = nodes[cur].links[queries[idx][pos++]-'a'];
				if (!(nodes[cur].type & PATTERN)) { continue; }
				gh[idx] += query(enter[cur]);
			}
		}
	}

	int64_t mx = gh[0], mn = gh[0];
	for (int i=1; i<s; ++i) {
		mx = max(mx, gh[i]);
		mn = min(mn, gh[i]);
	}

	printf("%" PRId64 " %" PRId64 "\n", mn, mx);
	return 0;
}
