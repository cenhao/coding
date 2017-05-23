#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	bool dfs(const vector<vector<int>> &ps, vector<bool> &vis, vector<int> &order, int cnt) {
		if (cnt == 4) {
			int dist = -1;
			for (int i=0; i<4; ++i) {
				int ni = (i+1) % 4, pi = (i-1+4) % 4;
				int x[2] = {ps[order[pi]][0] - ps[order[i]][0], ps[order[ni]][0] - ps[order[i]][0] };
				int y[2] = {ps[order[pi]][1] - ps[order[i]][1], ps[order[ni]][1] - ps[order[i]][1] };
				int dp = x[0] * x[1] + y[0] * y[1];
				if (dp != 0) { return false; }
				int td = (ps[order[i]][0]-ps[order[ni]][0]) * (ps[order[i]][0]-ps[order[ni]][0])
					+ (ps[order[i]][1]-ps[order[ni]][1]) * (ps[order[i]][1]-ps[order[ni]][1]);
				if (td == 0) { return false; }
				if (dist >= 0) {
					if (td != dist) { return false; }
				}

				dist = td;
			}

			return true;
		}

		for (int i=0; i<4; ++i) {
			if (vis[i]) { continue; }
			vis[i] = true;
			order[cnt] = i;
			if (dfs(ps, vis, order, cnt+1)) { return true; }
			vis[i] = false;
		}

		return false;
	}

	bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
		vector<vector<int>> ps(4);
		ps[0] = p1; ps[1] = p2; ps[2] = p3; ps[3] = p4;
		vector<bool> vis(4, false);
		vector<int> order(4);

		return dfs(ps, vis, order, 0);
	}
};

int main() {
	vector<vector<int>> ps;
	for (int i=0; i<4; ++i) {
		int x, y; cin >> x >> y;
		vector<int> p;
		p.push_back(x); p.push_back(y);
		ps.push_back(p);
	}

	Solution sol;
	cout << sol.validSquare(ps[0], ps[1], ps[2], ps[3]) << endl;
}
