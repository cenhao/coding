#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	struct DNode {
		DNode() { up = down = left = right = this; }
		DNode *up, *down, *left, *right;
		int x, y, cid;
	};

	void build(DNode &head, vector<DNode> &col, vector<DNode> &nodes, int n) {
		int end = n * 6 - 2;
		DNode *pre = &head;
		for (int i=0; i<end; ++i) {
			col[i].left = pre;
			col[i].right = pre->right;
			pre->right->left = &col[i];
			pre->right = &col[i];
			pre = &col[i];
			col[i].cid = i;
		}

		int ncnt = 0;
		for (int i=0; i<n; ++i) {
			for (int j=0; j<n; ++j) {
				int cidx[4] = { i, n+j, n*3+j-i-1, 4*n-1+(i+j) };
				pre = nullptr;
				for (int k=0; k<4; ++k) {
					DNode *cur = &nodes[ncnt++];
					cur->up = col[cidx[k]].up;
					cur->down = &col[cidx[k]];
					col[cidx[k]].up->down = cur;
					col[cidx[k]].up = cur;
					cur->x = i; cur->y = j; cur->cid = cidx[k];
					if (pre == nullptr) {
						pre = cur;
					} else {
						cur->left = pre;
						cur->right = pre->right;
						pre->right->left = cur;
						pre->right = cur;
						pre = cur;
					}
				}
			}
		}
	}

	void detatch(int cid, vector<DNode> &col) {
		col[cid].left->right = col[cid].right;
		col[cid].right->left = col[cid].left;
		for (DNode *i=col[cid].down; i!=&col[cid]; i=i->down) {
			for (DNode *j=i->right; j!=i; j=j->right) {
				j->up->down = j->down;
				j->down->up = j->up;
			}
		}
	}

	void retatch(int cid, vector<DNode> &col) {
		col[cid].left->right = &col[cid];
		col[cid].right->left = &col[cid];
		for (DNode *i=col[cid].down; i!=&col[cid]; i=i->down) {
			for (DNode *j=i->right; j!=i; j=j->right) {
				j->up->down = j;
				j->down->up = j;
			}
		}
	}

	void dance(DNode &head, vector<DNode> &col, vector<int> &xs, vector<int> &ys, vector<vector<string>> &ans, int depth, int n) {
		if (n == depth) {
			vector<string> tmp(n, string(n, '.'));
			for (int i=0; i<n; ++i) { tmp[xs[i]][ys[i]] = 'Q'; }
			ans.push_back(move(tmp));
			return;
		}
		DNode *cur = head.right;
		int cid = cur->cid;
		detatch(cid, col);
		for (DNode *i=cur->down; i!=cur; i=i->down) {
			xs[depth] = i->x; ys[depth] = i->y;
			for (DNode *j=i->right; j!=i; j=j->right) { detatch(j->cid, col); }
			dance(head, col, xs, ys, ans, depth+1, n);
			for (DNode *j=i->right; j!=i; j=j->right) { retatch(j->cid, col); }
		}
		retatch(cid, col);
	}

	vector<vector<string>> solveNQueens(int n) {
		DNode head;
		vector<DNode> col(6*n-2), nodes(n*n*n*4);
		vector<vector<string>> ans;
		vector<int> xs(n), ys(n);
		build(head, col, nodes, n);
		dance(head, col, xs, ys, ans, 0, n);
		return ans;
	}
};

int main() {
	int n; cin >> n;
	Solution sol;
	vector<vector<string>> ans = move(sol.solveNQueens(n));
	for (int i=0; i<ans.size(); ++i) {
		cout << i << endl;
		for (int j=0; j<ans[i].size(); ++j) {
			cout << ans[i][j] << endl;
		}
	}
	return 0;
}
