class Solution {
public:
	int maxDistance(vector<vector<int>>& arrays) {
		int sz = arrays.size();
		int mx[2] = {-1000000, 0}, mn[2] = { 10000000, 0}, mxp[2], mnp[2];
		for (int i=0; i<sz; ++i) {
			int ssz = arrays[i].size();
			if (arrays[i][0] < mn[0]) {
				mn[1] = mn[0]; mnp[1] = mnp[0];
				mn[0] = arrays[i][0], mnp[0] = i;
			} else if (arrays[i][0] < mn[1]) {
				mn[1] = arrays[i][0]; mnp[1] = i;
			}

			if (arrays[i][ssz-1] > mx[0]) {
				mx[1] = mx[0]; mxp[1] = mxp[0];
				mx[0] = arrays[i][ssz-1], mxp[0] = i;
			} else if (arrays[i][ssz-1] > mx[1]) {
				mx[1] = arrays[i][ssz-1]; mxp[1] = i;
			}
		}

		if (mxp[0] != mnp[0]) {
			return mx[0] - mn[0];
		} else {
			return max(abs(mx[0] - mn[1]), abs(mx[1] - mn[0]));
		}
	}
