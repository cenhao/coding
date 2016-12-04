#include <iostream>
#include <vector>
using namespace std;

class Solution {
	public:
	bool isConvex(vector<vector<int>>& points) {
		int size = points.size();
		bool p = false, n = false;
		for (int i=0; i<size; ++i) {
			int i1 = (i+1) % size;
			int i2 = (i+2) % size;
			int vx1 = points[i][0] - points[i1][0];
			int vy1 = points[i][1] - points[i1][1];
			int vx2 = points[i2][0] - points[i1][0];
			int vy2 = points[i2][1] - points[i1][1];
			int cp = vx1 * vy2 - vx2 * vy1;
			if (cp < 0) {
				n = true;
			} else if (cp > 0) {
				p = true;
			}
		}

		return !(p && n);
	}
};

int main() {
	int n; cin >> n;
	vector<vector<int>> ps(n, vector<int>(2, 0));
	for (int i=0; i<n; ++i) {
		cin >> ps[i][0] >> ps[i][1];
	}

	Solution sol;
	cout << sol.isConvex(ps) << endl;

	return 0;
}
