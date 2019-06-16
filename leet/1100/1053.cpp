#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	vector<int> prevPermOpt1(vector<int>& a) {
		map<int, int, greater<int>> hm;

		for (int i=a.size()-1; i>=0; --i) {
			auto iter = hm.upper_bound(a[i]);
			if (iter != hm.end()) {
				int idx = iter->second;
				swap(a[i], a[idx]);
				return a;
			}
			hm[a[i]] = i;
		}

		return a;
	}
};

int main() {
	int n; cin >> n;
	vector<int> a(n);
	for (int i=0; i<n; ++i) { cin >> a[i]; }
	Solution sol;
	auto ans = sol.prevPermOpt1(a);
	for (auto v: a) { cout << v << ' '; }
	cout << endl;
	return 0;
}
