class Solution {
public:
	int heightChecker(vector<int>& heights) {
		vector<int> hh = heights;
		sort(hh.begin(), hh.end());
		int cnt = 0;
		for (int i=0; i<hh.size(); ++i) {
			if (hh[i] != heights[i]) { ++cnt; }
		}
		return cnt;
	}
};
