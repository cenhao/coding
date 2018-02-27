#define invalid(p) \
	(p.x<0 || p.x>=rsz || p.y<0 || p.y>=csz || board[p.x][p.y]=='X' || id[p.x][p.y]!=0)

class Solution {
public:
	struct Pos { int x, y; };

	void solve(vector<vector<char>>& board) {
		int rsz = board.size();
		if (rsz == 0) { return; }
		int csz = board[0].size();

		vector<vector<int>> id(rsz, vector<int>(csz, 0));
		unordered_set<int> unsafe;
		int cid = 0;
		const int mov[4][2] = { {-1, 0}, {0, -1}, {1, 0}, {0, 1} };

		for (int i=0; i<rsz; ++i) {
			for (int j=0; j<csz; ++j) {
				if (board[i][j] == 'X' || id[i][j] != 0) { continue; }
				Pos tmp = { i, j };
				queue<Pos> q; q.push(tmp);
				id[i][j] = ++cid;

				bool safe = false;
				while (!q.empty()) {
					tmp = q.front(); q.pop();
					if (tmp.x==0 || tmp.x==rsz-1 || tmp.y==0 || tmp.y==csz-1) { safe = true; }
					for (int k=0; k<4; ++k) {
						Pos tmp1 = { tmp.x+mov[k][0], tmp.y+mov[k][1] };
						if (invalid(tmp1)) { continue; }

						id[tmp1.x][tmp1.y] = cid;
						q.push(tmp1);
					}
				}

				if (!safe) { unsafe.insert(cid); }
			}
		}

		for (int i=0; i<rsz; ++i) {
			for (int j=0; j<csz; ++j) {
				if (unsafe.find(id[i][j]) != unsafe.end()) { board[i][j] = 'X'; }
			}
		}
	}
};
