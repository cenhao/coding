class Solution {
public:
	bool isBoomerang(vector<vector<int>>& points) {
		int dx1 = points[0][0] - points[1][0];
		int dy1 = points[0][1] - points[1][1];
		int dx2 = points[0][0] - points[2][0];
		int dy2 = points[0][1] - points[2][1];
		bool ok = dx1 != 0 && dy1 != 0;
		ok &= dx2 != 0 && dy2 != 0;
		ok &= dx1 * dy2 != dx2 * dy1;
		return ok;
	}
};
