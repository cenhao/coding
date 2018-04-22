#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int numFactoredBinaryTrees(vector<int>& a) {
		const static int MOD = 1000000007;
		unordered_map<int, int> hm;
		sort(a.begin(), a.end());
		for (auto n: a) {
			hm[n] = 1;
			for (auto d: a) {
				if (d >= n) { break; }
				if (n % d != 0 || hm.find(n/d)==hm.end()) { continue; }
				int64_t v1 = hm[d], v2 = hm[n/d];
				int64_t cur = hm[n];
				cur = (cur + ((v1*v2) % MOD)) % MOD;
				hm[n] = cur;
			}
		}

		int ans = 0;
		for (auto &kvp: hm) {
			ans = (ans + kvp.second) % MOD;
		}
		return ans;
	}
};
int main() {
	int n; cin >> n;
	vector<int> a(n);
	for (int i=0; i<n; ++i) { cin >> a[i]; }
	Solution sol;
	cout << sol.numFactoredBinaryTrees(a) << endl;
	return 0;
}
