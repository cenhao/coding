#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
#include <cstring>
using namespace std;

class Solution {
	public:
		int numberOfBoomerangs(vector<pair<int, int> >& points) {
			int dist[510], ans = 0;
			for (int i=0, end=points.size(); i<end; ++i) {
				memset(dist, 0, sizeof(dist));
				dist[i] = -2;
				for (int j=0; j<end; ++j) {
					if (i == j) { continue; }
					int x = points[i].first - points[j].first;
					int y = points[i].second - points[j].second;
					int dist2 = x * x + y * y;
					dist[j] = dist2;
				}

				sort(dist, dist+end);
				int last = -1;
				int cnt = 0;
				for (int j=0; j<end; ++j) {
					if (dist[j] != last) {
						ans += (cnt * (cnt-1));
						last = dist[j];
						cnt = 0;
					}
					++cnt;
				}

				ans += (cnt * (cnt-1));
			}

			return ans;
		}
};

int main() {
	int n; cin >> n;
	vector<pair<int, int> > v;
	for (int i=0; i<n; ++i) {
		int a, b;
		cin >> a >> b;
		v.push_back(pair<int, int>(a, b));
	}

	Solution sol;
	cout << sol.numberOfBoomerangs(v) << endl;
	return 0;
}
