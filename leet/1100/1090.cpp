#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int largestValsFromLabels(vector<int>& values, vector<int>& labels, int num_wanted, int use_limit) {
		auto cmp = [](const pair<int, int> &p1, const pair<int, int> &p2) {
			return (p1.first == p2.first) ? p1.second < p2.second : p1.first < p2.first;
		};
		priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(cmp);
		int sz = values.size();
		for (int i=0; i<sz; ++i) {
			pq.emplace(make_pair(values[i], labels[i]));
		}

		int cnt = 0, ans = 0;
		unordered_map<int, int> hm;
		while (cnt < num_wanted && !pq.empty()) {
			auto p = pq.top(); pq.pop();
			auto it = hm.find(p.second);
			if (it==hm.end() || it->second<use_limit) {
				++cnt;
				ans += p.first;
				++hm[p.second];
			}
		}

		return ans;
	}
};

int main() {
	int n;
	vector<int> v(n), l(n);
	for (int i=0; i<n; ++i) { cin >> v[i]; }
	for (int i=0; i<n; ++i) { cin >> l[i]; }
	int nn, uu; cin >> nn >> uu;
	Solution sol;
	cout << sol.largestValsFromLabels(v, l, nn, uu) << endl;
	return 0;
}
