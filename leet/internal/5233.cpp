#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
		map<int, int> tm;
		int len = startTime.size();

		vector<int> idx(len);
		for (int i=0; i<len; ++i) { idx[i] = i; }
		sort(idx.begin(), idx.end(), [&endTime](const int a, const int b) {
			return endTime[a] > endTime[b];
		});

		for (int i=0; i<len; ++i) {
			auto it = tm.lower_bound(endTime[idx[i]]);
			int mxp = it==tm.end() ? 0 : it->second;
			int p = mxp + profit[idx[i]];

			it = tm.find(startTime[idx[i]]);
			if (it==tm.end()) {
				auto pit = tm.upper_bound(startTime[idx[i]]);
				if (pit != tm.end() && pit->second >= p) { continue; }
			} if (it->second >= p) {
				continue;
			}

			tm[startTime[idx[i]]] = p;
			it = tm.find(startTime[idx[i]]);

			while (it != tm.begin()) {
				int v = it->second;
				--it;
				if (it->second < v) {
					tm.erase(it);
					it = tm.find(startTime[idx[i]]);
				} else {
					break;
				}
			}
		}

		int mx = 0;
		for (auto &kvp: tm) {
			mx = max(mx, kvp.second);
		}
		return mx;
	}
};

int main() {
	int n; cin >> n;
	vector<int> st(n), ed(n), p(n);
	for (int i=0; i<n; ++i) { cin >> st[i]; }
	for (int i=0; i<n; ++i) { cin >> ed[i]; }
	for (int i=0; i<n; ++i) { cin >> p[i]; }
	Solution sol;
	cout << sol.jobScheduling(st, ed, p) << endl;
	return 0;
}
