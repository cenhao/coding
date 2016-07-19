/*
ID: cenhao11
PROG: prefix
LANG: C++11
*/

#include <stdio.h>
#include <string.h>

#define MAXL 11 /* \0 for index 10 */
#define MAXP 200
#define MAXS 200005

char primitives[MAXP][MAXL];
char sequence[MAXS];
bool reached[MAXS];

struct TrieNode {
	char val;
	bool isPrimitive;
	TrieNode* links[26];
}nodepool[MAXP * MAXL + 1]; /* 1 for root */
int nextNode = 0;

TrieNode* getNextNode(TrieNode* pcur, char val) {
	int need = val - 'A';
	TrieNode *pnode = pcur->links[need];

	if (pnode == NULL) {
		pnode = &nodepool[nextNode++];
		pnode->val = val;
		pnode->isPrimitive = false;
		memset(pnode->links, 0, sizeof(pnode->links));
		pcur->links[need] = pnode;
	}

	return pnode;
}

void buildTrie(int pcnt, char (*p)[MAXL]) {
	int root = 0;
	nextNode = 1;
	memset(nodepool[root].links, 0, sizeof(nodepool[root].links));

	for (int i=0; i<pcnt; ++i) {
		size_t len = strlen(p[i]);
		TrieNode *curnode = &nodepool[root];

		for (size_t j=0; j<len; ++j) {
			curnode = getNextNode(curnode, p[i][j]);
		}

		curnode->isPrimitive = true;
	}
}

int process(char *seq, bool* reached, TrieNode *root) {
	size_t len = strlen(seq);
	memset(reached, false, sizeof(bool)*(len+1));
	reached[0] = true;
	int mx = -1;

	for (int i=0; i<len; ++i) {
		if (!reached[i]) { continue; }

		TrieNode *cur = root;
		int pos = i; // current posistion
		while (cur) {
			cur = cur->links[seq[pos] - 'A'];
			++pos;
			if (cur && cur->isPrimitive) { reached[pos] = true; }
		}

		mx = i;
	}

	if (reached[len]) { mx = len; }
	return mx;
}

int main() {
	freopen("prefix.in", "r", stdin);
	freopen("prefix.out", "w", stdout);

	int pcnt = 0;
	do {
		scanf("%s", primitives[pcnt++]);
	} while (0 != strncmp(primitives[pcnt-1], ".", MAXL));
	--pcnt; // remove the last `.`

	int offset = 0;
	while (EOF != scanf("%s", &sequence[offset])) {
		offset += strlen(&sequence[offset]);
	}

	buildTrie(pcnt, primitives);
	printf("%d\n", process(sequence, reached, &nodepool[0]));
	return 0;
}
