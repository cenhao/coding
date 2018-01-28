#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int conv(const vector<vector<int>> &b) {
		int v = 0;
		for (int i=0; i<2; ++i) {
			for (int j=0; j<3; ++j) {
				v = v*10 + b[i][j];
			}
		}
		return v;
	}
	void rconv(int v, vector<vector<int>> &b, int &x, int &y) {
		for (int i=1; i>=0; --i) {
			for (int j=2; j>=0; --j) {
				b[i][j] = v % 10;
				v /= 10;
				if (b[i][j] == 0) { x = i; y = j; }
			}
		}
	}

	int slidingPuzzle(vector<vector<int>>& b) {
		int x, y;
		vector<int> cnt(1000000, -1);
		int cur = conv(b);
		cnt[cur] = 0;
		queue<int> q;
		q.push(cur);
		vector<vector<int>> tb(2, vector<int>(3));
		const int mov[4][2] = { {0,1}, {1,0}, {0,-1}, {-1,0} };

		while (!q.empty()) {
			cur = q.front(); q.pop();
			rconv(cur, tb, x, y);
			for (int i=0; i<4; ++i) {
				int xx = x+mov[i][0], yy = y+mov[i][1];
				if (xx < 0 || xx > 1 || yy < 0 || yy > 2) { continue; }
				swap(tb[x][y], tb[xx][yy]);
				int v = conv(tb);
				if (cnt[v] == -1) {
					cnt[v] = cnt[cur]+1;
					q.push(v);
				}
				swap(tb[x][y], tb[xx][yy]);
				if (v == 123450) { break; }
			}
		}

		return cnt[123450];
	}
};

int main() {
	vector<vector<int>> m(2, vector<int>(3));
	for (int i=0; i<2; ++i) {
		for (int j=0; j<3; ++j) { cin >> m[i][j]; }
	}

	Solution sol;
	cout << sol.slidingPuzzle(m) << endl;
	return 0;
}
