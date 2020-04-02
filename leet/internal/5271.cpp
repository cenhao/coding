class Solution {
public:
	int minTimeToVisitAllPoints(vector<vector<int>>& points) {
		int sz = points.size(), ans = 0;
		for (int i=1; i<sz; ++i) {
			ans += max(abs(points[i][0]-points[i-1][0]), abs(points[i][1]-points[i-1][1]));
		}
		return ans;
	}
};
