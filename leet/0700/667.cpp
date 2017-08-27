#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	vector<int> constructArray(int n, int k) {
		vector<int> ans(n, 0);
		ans[0] = 1;
		int adj[2] = { -1, 1 };
		for (int i=1; i<=k; ++i) {
			ans[i] = ans[i-1] + adj[i&1] * (k-i+1);
		}
		for (int i=k+1; i<n; ++i) { ans[i] = i+1; }
		return ans;
	}
};

int main() {
	int n, k; cin >> n >> k;
	Solution sol;
	vector<int> ans = sol.constructArray(n, k);
	for (int i=0; i<n; ++i) { cout << ans[i] << endl; }
	return 0;
}
