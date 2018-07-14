class Solution {
public:
	int matrixScore(vector<vector<int>>& a) {
		int rsz = a.size(), csz = a[0].size();
		vector<int> v(rsz, 0);
		int full = (1<<csz) - 1, hb = 1<<(csz-1);
		for (int i=0; i<rsz; ++i) {
			for (int j=0; j<csz; ++j) { v[i] = (v[i]<<1) | a[i][j]; }
			if (v[i] & hb) { v[i] = (~v[i]) & full; }
		}

		int mx = 0;
		for (int i=0; i<hb; ++i) {
			int sm = 0;
			for (int j=0; j<rsz; ++j) {
				v[j] ^= i;
				sm += v[j];
				v[j] ^= i;
			}

			mx = max(sm, mx);
		}
		return mx + hb * rsz;
	}
};
