#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
		int sz = people.size();
		sort(people.begin(), people.end(), [](const pair<int, int> &p1, const pair<int, int> &p2) {
			return p1.second != p2.second ? p1.second < p2.second : p1.first < p2.first;
		});

		list<int> lst;
		for (int i=0; i<sz; ++i) {
			auto it = lst.begin();
			int cnt = 0;
			while (it != lst.end()) {
				auto nxt = next(it);
				if (people[*it].first >= people[i].first) { ++cnt; }
				if (cnt >= people[i].second &&
					(nxt == lst.end() || people[i].first < people[*nxt].first)) {
					break;
				}
				++it;
			}

			lst.insert(it == lst.end() ? it : next(it), i);
		}

		vector<pair<int, int>> ans(sz);
		int cnt = 0;
		for (auto it=lst.begin(); it!=lst.end(); ++it) {
			ans[cnt++] = people[*it];
		}

		return ans;
	}
};

int main() {
	int n; cin >> n;
	vector<pair<int, int>> p(n);
	for (int i=0; i<n; ++i) {
		cin >> p[i].first >> p[i].second;
	}

	Solution sol;
	sol.reconstructQueue(p);
	return 0;
}
