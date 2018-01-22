#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int maxChunksToSorted(vector<int>& arr) {
		int sz = arr.size();

		vector<int> cp(arr.begin(), arr.end());
		sort(cp.begin(), cp.end());
		unordered_map<int, queue<int>> hm;
		for (int i=0; i<sz; ++i) {
			auto it = hm.find(cp[i]);
			if (it == hm.end()) {
				it = hm.insert(make_pair(cp[i], queue<int>())).first;
			}
			it->second.push(i);
		}

		int cnt = 0;
		for (int i=0, st=0, mx = -1, mn=0x7fffffff; i<sz; ++i) {
			auto it = hm.find(arr[i]);
			int idx = it->second.front(); it->second.pop();
			mn = min(mn, idx);
			mx = max(mx, idx);
			if (mn == st && mx == i) {
				++cnt;
				mn = 0x7fffffff; mx = i;
				st = i+1;
			}
		}

		return cnt;
	}
};

int main() {
	int n; cin >> n;
	vector<int> a(n);
	for (int i=0; i<n; ++i) { cin >> a[i]; }
	Solution sol;
	cout << sol.maxChunksToSorted(a) << endl;
	return 0;
}
