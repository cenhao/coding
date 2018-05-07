class Solution {
public:
	int minCostII(vector<vector<int>>& costs) {
		if (costs.empty() || costs[0].empty()) { return 0; }
		int sz = costs.size(), csz = costs[0].size();
		vector<vector<int>> pick(2, vector<int>(csz));
		vector<vector<int>> skip(2, vector<int>(csz));
		for (int i=0; i<csz; ++i) { skip[1][i] = 0; }
		for (int i=0; i<sz; ++i) {
			int mn = -1, pos, smn, spos;
			int cur = i & 1, pre = (i+1) & 1;
			for (int j=0; j<csz; ++j) {
				pick[cur][j] = costs[i][j] + skip[pre][j];
				if (mn==-1 || mn>pick[cur][j]) {
					smn = mn; spos = pos;
					mn = pick[cur][j]; pos = j;
				} else if (smn==-1 || smn>pick[cur][j]) {
					smn = pick[cur][j]; spos = j;
				}
			}
			for (int j=0; j<csz; ++j) {
				skip[cur][j] = (j == pos) ? smn : mn;
			}
		}
		int ans = -1, cur = (sz-1) & 1;
		for (int i=0; i<csz; ++i) {
			if (ans==-1 || pick[cur][i]<ans) { ans = pick[cur][i]; }
		}

		return ans;
	}
};
