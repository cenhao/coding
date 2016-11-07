#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
	public:
		int findMinArrowShots(vector<pair<int, int> >& points) {
			if (points.size() == 0) { return 0; }

			sort(points.begin(), points.end(), cmp);
			int start = points[0].first, end = points[0].second;
			int cnt = 0;
			for (int i=1, stop=points.size(); i<stop; ++i) {
				if (points[i].second <= end) { // within
					start = points[i].first;
					end = points[i].second;
				} else if (points[i].first > end) {
					start = points[i].first;
					end = points[i].second;
					++cnt;
				} else {
					start = points[i].first;
				}
			}
			++cnt;

			return cnt;
		}

		static bool cmp(const pair<int, int> &p1, const pair<int, int> &p2) {
			if (p1.first == p2.first) {
				return p1.second > p2.second;
			}

			return p1.first < p2.first;
		}
};

int main() {
	int n; cin >> n;
	vector<pair<int, int> > v;
	for (int i=0; i<n; ++i) {
		int a, b; cin >> a >> b;
		v.push_back(pair<int, int>(a, b));
	}
	Solution sol;
	cout << sol.findMinArrowShots(v) << endl;
	return 0;
}
