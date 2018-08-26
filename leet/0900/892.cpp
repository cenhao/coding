class Solution {
public:
	int surfaceArea(vector<vector<int>>& g) {
		int rsz = g.size(), csz = g.size();
		int hs = 0, sz = 0;
		vector<int> ys(csz, 0);
		for (int i=0; i<rsz; ++i) {
			int xs = 0;
			for (int j=0; j<csz; ++j) {
				if (g[i][j] != 0) { sz += 2; }
				sz += abs(g[i][j] - xs);
				xs = g[i][j];
				sz += abs(g[i][j] - ys[j]);
				ys[j] = g[i][j];
			}
			sz += xs;
		}

		for (auto v: ys) { sz += v; }
		return sz;
	}
};
