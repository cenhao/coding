class Solution {
public:
	bool checkStraightLine(vector<vector<int>>& c) {
		sort(c.begin(), c.end(), [](const vector<int> &v1, const vector<int> &v2) {
			return v1.at(0) < v2.at(0);
		});
		
		if (c[0][0] == c[1][0]) { return false; }

		int64_t dy = c[1][1] - c[0][1], dx = c[1][0] - c[0][0];
		for (int i=2; i<c.size(); ++i) {
			if ((c[i][0]-c[0][0])*dy != (c[i][1]-c[0][1])*dx) {
				return false;
			}
		}

		return true;
	}
};
