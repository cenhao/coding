class Solution {
public:
	struct State {
		int x, y, s, c;
		State(int xx, int yy, int ss, int cc) {
			x = xx; y = yy; s = ss; c = cc;
		}
	};
	int shortestPathAllKeys(vector<string>& g) {
		int rsz = g.size(), csz = g[0].size();
		int sx, sy, k = -1;
		for (int i=0; i<rsz; ++i) {
			for (int j=0; j<csz; ++j) {
				if (g[i][j] == '@') {
					sx = i; sy = j;
				} else if (g[i][j]>='a' && g[i][j]<'z') {
					k = max(k, g[i][j]-'a');
				}
			}
		}
		++k;
		int ssz = 1 << k, full = (1<<k) - 1;;
		vector<vector<vector<int>>> dist(rsz, vector<vector<int>>(csz, vector<int>(ssz, -1)));
		dist[sx][sy][0] = 0;
		auto cmp = [](const State &s1, const State &s2) { return s1.c > s2.c; };
		priority_queue<State, vector<State>, decltype(cmp)> pq(cmp);
		pq.emplace(sx, sy, 0, 0);
		int ans = -1;
		const int mov[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

		while (!pq.empty()) {
			auto cs = pq.top(); pq.pop();
			if (cs.c > dist[cs.x][cs.y][cs.s]) { continue; }
			if (cs.s == full) {
				if (ans==-1 || cs.c<ans) { ans = cs.c; }
				continue;
			}
			int xx, yy, ss, cc = cs.c + 1;
			for (int i=0; i<4; ++i) {
				xx = cs.x + mov[i][0], yy = cs.y + mov[i][1];
				ss = cs.s;
				if (xx<0||xx>=rsz||yy<0||yy>=csz||g[xx][yy]=='#') { continue; }
				if (g[xx][yy]>='A' && g[xx][yy]<='Z') {
					int l = g[xx][yy] - 'A';
					if ((cs.s & (1<<l)) == 0) { continue; }
				}
				if (g[xx][yy]>='a' && g[xx][yy]<='z') {
					int key = g[xx][yy] - 'a';
					ss |= 1 << key;
				}

				if (dist[xx][yy][ss]!=-1 && cc>=dist[xx][yy][ss]) { continue; }
				dist[xx][yy][ss] = cc;
				pq.emplace(xx, yy, ss, cc);
			}
		}

		return ans;
	}
};
