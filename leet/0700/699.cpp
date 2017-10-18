class Solution {
public:
	vector<int> fallingSquares(vector<pair<int, int>>& positions) {
		int sz = positions.size();
		vector<int> ans(sz, 0), h(sz, 0);
		for (int i=0; i<sz; ++i) {
			int v = 0;
			for (int j=i-1; j>=0; --j) {
				if (!(positions[i].first>=positions[j].first+positions[j].second ||
					positions[i].first+positions[i].second<=positions[j].first)) {
					v = max(v, h[j]);
				}
			}

			h[i] = v + positions[i].second;
			ans[i] = (i == 0 || h[i] > ans[i-1]) ? h[i] : ans[i-1];
		}

		return ans;
	}
};
