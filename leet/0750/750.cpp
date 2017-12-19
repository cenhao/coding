class Solution {
public:
	int countCornerRectangles(vector<vector<int>>& g) {
		int rsz = g.size();
		if (rsz <= 1) { return 0; }
		int csz = g[0].size();
		if (csz <= 1) { return 0; }

		vector<vector<int>> cnt(csz, vector<int>(csz, 0));
		vector<int> pre_one(csz);
		int pcnt, ans = 0;
		for (int i=0; i<rsz; ++i) {
			pcnt = 0;
			for (int j=0; j<csz; ++j) {
				if (g[i][j] == 0) { continue; }
				for (int k=0; k<pcnt; ++k) {
					ans += cnt[pre_one[k]][j];
					++cnt[pre_one[k]][j];
				}

				pre_one[pcnt++] = j;
			}
		}

		return ans;
	}
	/*
	int countCornerRectangles(vector<vector<int>>& grid) {
		int rsz = grid.size();
		if (rsz <= 1) { return 0; }
		int csz = grid[0].size();
		if (csz <= 1) { return 0; }
		vector<vector<uint64_t>> bm(csz, vector<uint64_t>(4, 0));
		int ans = 0;
		for (int i=0; i<rsz; ++i) {
			vector<int> pc(csz, 0);
			int cnt = 0;
			for (int j=0; j<csz; ++j) {
				if (grid[i][j] == 0) { continue; }
				int sans = 0;
				for (int k=0; k<cnt; ++k) {
					for (int bi=0; bi<4; ++bi) {
						uint64_t av = bm[pc[k]][bi] & bm[j][bi];
						while (av > 0) {
							++sans;
							av -= (av & (~(av-1)));
						}
					}
				}

				int idx = i / 64, bidx = i % 64;
				bm[j][idx] |= 1LL << bidx;
				ans += sans;
				pc[cnt++] = j;
			}
		}

		return ans;
	}
	*/
};
