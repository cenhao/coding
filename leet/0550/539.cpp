#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
	int findMinDifference(vector<string>& timePoints) {
		vector<int> t(timePoints.size() + 1);
		int mn = 0x7fffffff, h, m;
		for (int i=0, end=timePoints.size(); i<end; ++i) {
			sscanf(timePoints[i].c_str(), "%d:%d", &h, &m);
			t[i] = h * 60 + m;
			mn = min(mn, t[i]);
		}

		t[timePoints.size()] = mn + 24 * 60;
		sort(t.begin(), t.end());
		mn = 0x7fffffff;
		for (int i=1; i<t.size(); ++i) {
			mn = min(mn, t[i]-t[i-1]);
		}

		return mn;
	}
};

int main() {
	string t0 = "23:59";
	string t1 = "00:00";
	vector<string> v(2);
	v[0] = t0; v[1] = t1;
	Solution sol;
	sol.findMinDifference(v);
	return 0;
}
