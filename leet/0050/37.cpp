#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	struct DNode {
		DNode() { up = down = left = right = this; }
		DNode *up, *down, *left, *right;
		int cid;
		int x, y, v;
	} head, col[81*4], nodes[81*9*4+10];
	int ncnt;
	bool rmark[9][9], cmark[9][9], gmark[9][9];

	void insert(int v, int x, int y) {
		int g[4];
		g[0] = x * 9 + y;
		g[1] = 81 + x * 9 + v;
		g[2] = 81 * 2 + y * 9 + v;
		g[3] = 81 * 3 + (x / 3 * 3 + y / 3) * 9 + v;

		DNode *pre = nullptr;
		for (int i=0; i<4; ++i) {
			int cur = ncnt++;
			nodes[cur].up = col[g[i]].up;
			nodes[cur].down = &col[g[i]];
			nodes[cur].cid = g[i];
			nodes[cur].x = x; nodes[cur].y = y; nodes[cur].v = v;
			col[g[i]].up->down = &nodes[cur];
			col[g[i]].up = &nodes[cur];

			if (pre == nullptr) {
				pre = &nodes[cur];
			} else {
				nodes[cur].left = pre->left;
				nodes[cur].right = pre;
				pre->left->right = &nodes[cur];
				pre->left = &nodes[cur];
			}
		}
	}

	void build(const vector<vector<char>> &board) {
		DNode *pre = &head;
		for (int i=0; i<81*4; ++i) {
			col[i].left = pre;
			col[i].right = pre->right;
			col[i].cid = i;
			pre->right->left = &col[i];
			pre->right = &col[i];
			pre = &col[i];
		}

		memset(rmark, false, sizeof(rmark));
		memset(cmark, false, sizeof(cmark));
		memset(gmark, false, sizeof(gmark));

		for (int i=0; i<9; ++i) {
			for (int j=0; j<9; ++j) {
				if (board[i][j] == '.') { continue; }
				int id = board[i][j] - '1', gid = i/3*3 + j/3;
				rmark[i][id] = true;
				cmark[j][id] = true;
				gmark[gid][id] = true;
			}
		}

		ncnt = 0;
		for (int i=0, sz=board.size(); i<sz; ++i) {
			for (int j=0, vsz=board[i].size(); j<vsz; ++j) {
				if (board[i][j] != '.') {
					insert(board[i][j] - '1', i, j);
				} else {
					int gid = i/3*3 + j/3;
					for (int k=0; k<9; ++k) {
						if (!rmark[i][k] && !cmark[j][k] && !gmark[gid][k]) {
							insert(k, i, j);
						}
					}
				}
			}
		}
	}

	void detatch(int cid) {
		col[cid].left->right = col[cid].right;
		col[cid].right->left = col[cid].left;

		for (DNode *i=col[cid].down; i!=&col[cid]; i=i->down) {
			for (DNode *j=i->right; j!=i; j=j->right) {
				j->up->down = j->down;
				j->down->up = j->up;
			}
		}
	}

	void retatch(int cid) {
		col[cid].left->right = &col[cid];
		col[cid].right->left = &col[cid];

		for (DNode *i=col[cid].down; i!=&col[cid]; i=i->down) {
			for (DNode *j=i->right; j!=i; j=j->right) {
				j->up->down = j;
				j->down->up = j;
			}
		}
	}

	bool dance(vector<vector<char>> &board) {
		DNode *cur = head.right;
		if (cur == &head) { return true; }
		int cid = cur->cid;
		detatch(cid);
		for (DNode *i=cur->down; i!=cur; i=i->down) {
			for (DNode *j=i->right; j!=i; j=j->right) { detatch(j->cid); }
			if (dance(board)) {
				board[i->x][i->y] = i->v + '1';
				return true;
			}
			for (DNode *j=i->right; j!=i; j=j->right) { retatch(j->cid); }
		}
		retatch(cid);
		return false;
	}

	void solveSudoku(vector<vector<char>>& board) {
		build(board);
		dance(board);
	}
};

int main() {
	vector<vector<char>> board(9, vector<char>(9));
	string buff;
	for (int i=0; i<9; ++i) {
		cin >> buff;
		for (int j=0; j<9; ++j) { board[i][j] = buff[j]; }
	}

	Solution sol;
	sol.solveSudoku(board);
	for (int i=0; i<9; ++i) {
		for (int j=0; j<9; ++j) { cout << board[i][j]; }
		cout << endl;
	}

	return 0;
}
