#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	bool isPossible(vector<int>& target) {
		priority_queue<int> pq(target.begin(), target.end());
		int64_t sm = 0;
		int onecnt = 0;
		for (auto t: target) {
			sm += t;
			if (t == 1) { ++onecnt; }
		}

		while (onecnt < target.size()) {
			int t = pq.top();
			pq.pop();
			int nv = (sm-t == 1) ? 1 : t % (sm - t);
			if (t==nv || nv<1) { return false; }
			if (nv == 1) { ++onecnt; }
			sm = sm - t + nv;
			pq.push(nv);
		}

		return true;
	}
};

int main() {
	int n; cin >> n;
	vector<int> t(n);
	for (int i=0; i<n; ++i) { cin >> t[i]; }
	Solution sol;
	cout << sol.isPossible(t) << endl;
	return 0;
}
