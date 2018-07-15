#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	vector<int> advantageCount(vector<int>& A, vector<int>& b) {
		map<int, int> hm;
		for (auto a: A) { ++hm[a]; }
		int sz = b.size();
		vector<int> idx(sz);
		for (int i=0; i<sz; ++i) { idx[i] = i; }
		sort(idx.begin(), idx.end(), [&b] (int i1, int i2) {
			return b[i1] < b[i2];
		});

		vector<pair<int ,int>> tmp;
		for (auto i: idx) {
			auto it = hm.upper_bound(b[i]);
			if (it == hm.end()) { it = hm.begin(); }
			tmp.emplace_back(i, it->first);
			if (--it->second == 0) { hm.erase(it); }
		}

		vector<int> ans(sz);
		for (auto &p: tmp) { ans[p.first] = p.second; }

		return ans;
	}
};

int main() {
	vector<int> a = { 12,24,8,32 }, b = {13,25,32,11 };
	Solution sol;
	sol.advantageCount(a, b);
	return 0;
}
