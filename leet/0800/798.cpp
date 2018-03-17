#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int bestRotation(vector<int>& a) {
		int sz = a.size();
		vector<pair<int, int>> ps;
		for (int i=0; i<sz; ++i) {
			int st = i+1, ed = sz-a[i]+i;
			if (ed < sz) {
				ps.push_back(make_pair(st, ed));
			} else if (st < sz) {
				ps.push_back(make_pair(st, sz-1));
				ps.push_back(make_pair(0, ed%sz));
			} else {
				ps.push_back(make_pair(st%sz, ed%sz));
			}
		}

		sort(ps.begin(), ps.end(), [](const pair<int, int> &p1, const pair<int, int> &p2) {
			return p1.first < p2.first;
		});

		priority_queue<int, vector<int>, greater<int>> hp;
		int psz = ps.size();
		int mx = 0, ans;
		for (int i=0, pos=0; i<sz; ++i) {
			while (!hp.empty() && hp.top()<i) { hp.pop(); }
			while (pos<psz && ps[pos].first==i) {
				hp.push(ps[pos++].second);
			}

			if ((int)hp.size() > mx) {
				mx = hp.size();
				ans = i;
			}
		}

		return ans;
	}
};
int main() {
	int n; cin >> n;
	vector<int> a(n);
	for (int i=0; i<n; ++i) { cin >> a[i]; }
	Solution sol;
	cout << sol.bestRotation(a) << endl;
	return 0;
}
