class Solution {
public:
	int maxSatisfied(vector<int>& c, vector<int>& g, int x) {
		int sz = c.size();
		int sm = 0;
		for (int i=0; i<sz; ++i) { sm += (g[i] == 1) ? 0 : c[i]; }

		int mx = 0, tmp = 0;
		for (int i=0; i<sz; ++i) {
			tmp += (g[i] == 1) ? c[i] : 0;
			if (i >= x) {
				tmp -= (g[i-x] == 1) ? c[i-x] : 0;
			}
			mx = max(tmp, mx);
		}

		return sm + mx;
	}
};
