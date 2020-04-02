#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int find(vector<int> &r, int pv, int pos, int cnt) {
		if (cnt == 3) { return 1; }
		if (pos >= r.size()) { return 0; }
		int ans = 0;
		for (int i=pos; i<r.size(); ++i) {
			if (r[i] <= pv) { continue; }
			ans += find(r, r[i], i+1, cnt+1);
		}
		return ans;
	}
	int numTeams(vector<int>& rating) {
		int ans = find(rating, -1, 0, 0);
		for (int i=0; i<rating.size(); ++i) { rating[i] = -rating[i]; }
		ans += find(rating, -10000000, 0, 0);
		return ans;
	}
};

int main() {
	int n; cin >> n;
	vector<int> a(n);
	for (int i=0; i<n; ++i) { cin >> a[i]; }
	Solution sol;
	cout << sol.numTeams(a) << endl;
	return 0;
}
