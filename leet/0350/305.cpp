class Solution {
#define GET_IDX(p) (p.first*n+p.second)
	int get(int x, vector<int> &f) {
		return f[x] = (f[x] == f[f[x]] ? f[x] : get(f[x], f));
	}
public:
	vector<int> numIslands2(int m, int n, vector<pair<int, int>>& positions) {
		const static int mov[4][2] = { {-1, 0}, {0, -1}, {1, 0}, {0, 1} };
		vector<int> f(m*n, -1);
		vector<int> ans;
		int cnt = 0;
		for (auto &p: positions) {
			++cnt;
			int idx = GET_IDX(p);
			f[idx] = idx;
			for (int i=0; i<4; ++i) {
				auto np = make_pair(p.first+mov[i][0], p.second+mov[i][1]);
				if (np.first<0 || np.first>=m || np.second<0 || np.second>=n) { continue; }
				int nidx = GET_IDX(np);
				if (f[nidx] != -1) {
					int p1 = get(nidx, f);
					int p2 = get(idx, f);
					if (p1 != p2) {
						--cnt;
						f[p2] = p1;
					}
				}
			}
			ans.push_back(cnt);
		}
		return ans;
	}
};
