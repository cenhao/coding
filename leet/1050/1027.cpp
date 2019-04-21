#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int proc(const vector<pair<int, int>> &vec) {
		int sz = vec.size();
		vector<unordered_map<int, int>> vhm(sz);
		int mx = 0;
		for (int i=1; i<sz; ++i) {
			for (int j=i-1; j>=0; --j) {
				if (vec[i].second < vec[j].second) { continue; }
				int delta = vec[i].first - vec[j].first, v;
				auto iter = vhm[j].find(delta);
				if (iter != vhm[j].end()) {
					v = iter->second + 1;
				} else {
					v = 1;
				}

				iter = vhm[i].find(delta);
				if (iter == vhm[i].end()) {
					vhm[i][delta] = v;
				} else {
					iter->second = max(iter->second, v);
				}
				mx = max(v, mx);
			}
		}

		return mx;
	}
	int longestArithSeqLength(vector<int>& a) {
		vector<pair<int, int>> inc, dec;
		int sz = a.size();
		for (int i=0; i<sz; ++i) {
			inc.emplace_back(make_pair(a[i], i));
			dec.emplace_back(make_pair(a[i], i));
		}

		sort(inc.begin(), inc.end(), [](const pair<int, int> &p1, const pair<int, int> &p2) {
			return p1.first < p2.first;
		});
		sort(dec.begin(), dec.end(), [](const pair<int, int> &p1, const pair<int, int> &p2) {
			return p1.first > p2.first;
		});

		int ans = proc(inc);
		ans = max(ans, proc(dec));
		return ans + 1;
	}
};

int main() {
	int n; cin >> n;
	vector<int> a(n);
	for (int i=0; i<n; ++i) { cin >> a[i]; }
	Solution sol;
	cout << sol.longestArithSeqLength(a) << endl;
	return 0;
}
