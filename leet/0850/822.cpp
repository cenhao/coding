class Solution {
public:
	int flipgame(vector<int>& fronts, vector<int>& backs) {
		int sz = fronts.size();
		int ans = -1;
		for (int i=0; i<sz; ++i) {
			if (fronts[i] == backs[i]) { continue; }
			if (ans == -1 || fronts[i] < ans) {
				bool ok = true;
				for (int j=0; j<sz; ++j) {
					if (i == j) { continue; }
					if (fronts[j] == fronts[i] && backs[j] == fronts[i]) {
						ok = false;
						break;
					}
				}
				if (ok) { ans = fronts[i]; }
			}
			if (ans == -1 || backs[i] < ans) {
				bool ok = true;
				for (int j=0; j<sz; ++j) {
					if (i == j) { continue; }
					if (fronts[j] == backs[i] && backs[j] == backs[i]) {
						ok = false;
						break;
					}
				}
				if (ok) { ans = backs[i]; }
			}
		}
		return ans == -1 ? 0 : ans;
	}
};
