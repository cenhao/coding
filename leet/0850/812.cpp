#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	double largestTriangleArea(vector<vector<int>>& points) {
		int sz = points.size();
		double mx = 0;
		for (int i=0; i<sz; ++i) {
			for (int j=i+1; j<sz; ++j) {
				for (int k=j+1; k<sz; ++k) {
					int tmp = points[i][0]*(points[j][1]-points[k][1]) +
						points[j][0]*(points[k][1]-points[i][1]) +
						points[k][0]*(points[i][1]-points[j][1]);
					double dtmp = abs(tmp) * 0.5;
					mx = max(dtmp, mx);
				}
			}
		}
		return mx;
	}
};

int main() {
	int n; cin >> n;
	vector<vector<int>> p(n, vector<int>(2));
	for (int i=0; i<n; ++i) { cin >> p[i][0] >> p[i][1]; }
	Solution sol;
	cout << sol.largestTriangleArea(p) << endl;
	return 0;
}
