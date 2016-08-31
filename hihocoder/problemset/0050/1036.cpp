/*
 * hihocode 1036, trie graph basic
 * The optimization mentioned in the page is in fact really good.
 */

#include <queue>
using namespace std;

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXN 1000000
#define MAXM 1000000
#define MAXL 26
#define ROOT 0

struct TrieGraphNode {
	int fail;
	int complete;
	int links[26];
} nodes[MAXN+1];
int first;

struct QueueItem {
	int parent;
	int child;
	int edge;
};

char text[MAXM+1];
char word[MAXN+1];
queue<QueueItem> q;

void init() {
	memset(nodes, 0, sizeof(nodes));
	first = ROOT + 1;
}

void insert(char *word) {
	int cur = ROOT;
	for (int lv=0, len=strlen(word); lv<len; ++lv) {
		int idx = word[lv] - 'a';
		int nxt = nodes[cur].links[idx];
		if (nxt <= 0) {
			nxt = first++;
			nodes[cur].links[idx] = nxt;
		}

		cur = nxt;
	}

	nodes[cur].complete = cur;
}

void buildTrieGraph(int idx, int parent, int cur) {
	if (parent == 0) {
		nodes[cur].fail = 0;
	} else {
		int pf = nodes[parent].fail;
		while (pf != ROOT && nodes[pf].links[idx] <= 0) { pf = nodes[pf].fail; }
		if (nodes[pf].links[idx] > 0) { pf = nodes[pf].links[idx]; }
		if (nodes[cur].complete <= 0) { nodes[cur].complete = nodes[pf].complete; }
		nodes[cur].fail = pf;
	}

	for (int i=0; i<MAXL; ++i) {
		if (nodes[cur].links[i] <= 0) {
			nodes[cur].links[i] = -abs(nodes[nodes[cur].fail].links[i]);
		} else {
			QueueItem item = { cur, nodes[cur].links[i], i };
			q.push(item);
		}
	}
}

void buildTrieGraph() {
	for (int i=0; i<MAXL; ++i) {
		if (nodes[ROOT].links[i] <= 0) { continue; }
		QueueItem item = { 0, nodes[ROOT].links[i], i };
		q.push(item);
	}

	while (!q.empty()) {
		QueueItem item = q.front();
		q.pop();
		buildTrieGraph(item.edge, item.parent, item.child);
	}
}

bool match() {
	int cur = ROOT;
	for (int lv=0, len=strlen(text); lv<len; ++lv) {
		int idx = text[lv] - 'a';
		cur = abs(nodes[cur].links[idx]);
		if (nodes[cur].complete > 0) { return true; }
	}

	return false;
}

int main() {
	init();
	int n;
	scanf("%d\n", &n);

	for (int i=0; i<n; ++i) {
		scanf("%s", word);
		insert(word);
	}

	buildTrieGraph();
	scanf("%s", text);
	printf("%s\n", match() ? "YES" : "NO");
	return 0;
}
