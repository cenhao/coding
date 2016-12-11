#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
	public:
	int findRadius(vector<int>& houses, vector<int>& heaters) {
		sort(houses.begin(), houses.end());
		sort(heaters.begin(), heaters.end());

		vector<int> mn = vector<int>(houses.size(), 0x7fffffff);

		for (int i=0, cur=0, end=houses.size(); i<end; ++i) {
			while (cur < heaters.size() && houses[i] > heaters[cur]) { ++cur; }
			if (cur >= heaters.size()) { break; }
			mn[i] = min(mn[i], heaters[cur] - houses[i]);
		}

		for (int i=houses.size()-1, cur=heaters.size()-1; i>=0; --i) {
			while (cur >= 0 && houses[i] < heaters[cur]) { --cur; }
			if (cur < 0) { break; }
			mn[i] = min(mn[i], houses[i] - heaters[cur]);
		}

		int mx = 0;
		for (auto m : mn) {
			mx = max(m, mx);
		}

		return mx;
	}
};

int main() {
	int n; cin >> n;
	vector<int> houses = vector<int>(n);
	for (int i=0; i<n; ++i) { cin >> houses[i]; }

	int m; cin >> m;
	vector<int> heaters = vector<int>(m);
	for (int i=0; i<m; ++i) { cin >> heaters[i]; }

	Solution sol;
	cout << sol.findRadius(houses, heaters) << endl;
	return 0;
}
