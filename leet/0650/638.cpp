class Solution {
public:
	int dp[7][7][7][7][7][7];
	int& get(vector<int> &idx) {
		return dp[idx[0]][idx[1]][idx[2]][idx[3]][idx[4]][idx[5]];
	}

	void dfs(const vector<int> &price, const vector<int> &needs, const vector<int> &sp, vector<int> &idx, int d) {
		if (d >= price.size()) {
			vector<int> nidx(idx);
			for (int i=0; i<d; ++i) {
				nidx[i] -= sp[i];
			}
			int pv = get(nidx);
			if (pv < 0) { return; }
			int &cv = get(idx);
			if (cv < 0 || pv + sp[d] < cv) {
				cv = pv + sp[d];
			}
			return;
		}
		for (int i=sp[d]; i<=needs[d]; ++i) {
			idx[d] = i;
			dfs(price, needs, sp, idx, d+1);
		}
	}

	int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
		memset(dp, -1, sizeof(dp));
		vector<int> idx(6, 0);
		get(idx) = 0;
		int sz = price.size();
		for (int i=0; i<sz; ++i) { idx[i] = needs[i]; }

		for (int i=0; i<sz; ++i) {
			vector<int> soffer(sz+1, 0);
			soffer[i] = 1;
			soffer[sz] = price[i];
			special.push_back(soffer);
		}

		vector<int> nidx(6, 0);
		for (auto &sp : special) {
			dfs(price, needs, sp, nidx, 0);
		}

		return get(idx);
	}
};
