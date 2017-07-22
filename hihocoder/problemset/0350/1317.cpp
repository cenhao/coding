#include <bits/stdc++.h>
using namespace std;

#define MAXN 100

int mat[MAXN][MAXN];
struct DancingNode {
	DancingNode *up, *down, *left, *right;
	int row, col;
	void reset() { up = down = left = right = this; }
} head, ct[MAXN], nodes[MAXN*MAXN+1];

void build(int n, int m) {
	head.reset();
	DancingNode *pre = &head;
	for (int i=0; i<m; ++i) {
		ct[i].reset();
		ct[i].left = pre;
		ct[i].right = pre->right;
		ct[i].col = i;
		pre->right->left = &ct[i];
		pre->right = &ct[i];
		pre = &ct[i];
	}

	int ncnt = 1;
	for (int i=0; i<n; ++i) {
		pre = nullptr;
		for (int j=0; j<m; ++j) {
			if (mat[i][j] == 0) { continue; }
			int cur = mat[i][j] = ncnt++;
			nodes[cur].reset();
			nodes[cur].row = i; nodes[cur].col = j;
			nodes[cur].up = ct[j].up;
			nodes[cur].down = &ct[j];
			ct[j].up->down = &nodes[cur];
			ct[j].up = &nodes[cur];

			if (pre == nullptr) {
				pre = &nodes[cur];
			} else {
				nodes[cur].right = pre;
				nodes[cur].left = pre->left;
				pre->left->right = &nodes[cur];
				pre->left = &nodes[cur];
			}
		}
	}
}

void detatch(int idx) {
	ct[idx].left->right = ct[idx].right;
	ct[idx].right->left = ct[idx].left;

	for (DancingNode *i=ct[idx].down; i!=&ct[idx]; i=i->down) {
		for (DancingNode *j=i->right; j!=i; j=j->right) {
			j->up->down = j->down;
			j->down->up = j->up;
		}
	}
}

void retatch(int idx) {
	ct[idx].left->right = &ct[idx];
	ct[idx].right->left = &ct[idx];

	for (DancingNode *i=ct[idx].down; i!=&ct[idx]; i=i->down) {
		for (DancingNode *j=i->right; j!=i; j=j->right) {
			j->up->down = j;
			j->down->up = j;
		}
	}
}

bool dance(int depth) {
	DancingNode *cur = head.right;
	if (cur == &head) { return true; }
	int idx = cur->col;
	detatch(idx);
	for (DancingNode *i=ct[idx].down; i!=&ct[idx]; i=i->down) {
		for (DancingNode *j=i->right; j!=i; j=j->right) { detatch(j->col); }
		if (dance(depth+1)) { return true; }
		for (DancingNode *j=i->right; j!=i; j=j->right) { retatch(j->col); } }
	retatch(idx);
	return false;
}

int main() {
	int t; scanf("%d", &t);
	while (t--) {
		int n, m; scanf("%d%d", &n, &m);
		for (int i=0; i<n; ++i) {
			for (int j=0; j<m; ++j) { scanf("%d", &mat[i][j]); }
		}

		build(n, m);
		printf(dance(0) ? "Yes\n" : "No\n");
	}

	return 0;
}
