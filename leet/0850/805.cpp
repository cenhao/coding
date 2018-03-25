#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	bool dfs(int cur, int csm, int cnt, const int sm, vector<int> &a) {
		int sz = a.size();
		++cnt;
		if (cnt == sz) { return false; }
		for (int i=cur; i<sz; ++i) {
			int tmp = csm + a[i];
			int lv = tmp * (sz-cnt), rv = (sm-tmp) * cnt;
			if (lv == rv) {
				return true;
			}
			if (lv > rv) { break; }
			if (dfs(i+1, tmp, cnt, sm, a)) { return true; }
		}
		return false;
	}
	bool splitArraySameAverage(vector<int>& a) {
		int sz = a.size();
		sort(a.begin(), a.end());
		int sm = 0;
		for (int i=0; i<sz; ++i) { sm += a[i]; }
		return dfs(0, 0, 0, sm, a);
	}
};

int main() {
	int n; cin >> n;
	vector<int> a(n);
	for (int i=0; i<n; ++i) { cin >> a[i]; }
	Solution sol;
	cout << sol.splitArraySameAverage(a) << endl;
	return 0;
}
