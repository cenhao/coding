#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	void dfs(int need, string &ans, const vector<int> &frac, vector<bool> &vis) {
		int idx = frac.size() - ans.length() - 2;
		int take = (idx >= 0) ? (need/frac[idx]) : 0, cnt = 0;
		for (int i=0; i<frac.size(); ++i) {
			if (vis[i]) { continue; }
			if (++cnt > take) {
				vis[i] = true;
				ans += i + '1';
				break;
			}
		}

		if (idx >= 0) { dfs(need-frac[idx]*take, ans, frac, vis); }
	}

	string getPermutation(int n, int k) {
		vector<bool> vis(n, false);
		vector<int> frac(n, 1);
		for (int i=1; i<n; ++i) { frac[i] = frac[i-1]*(i+1); }
		string ans = "";
		dfs(k-1, ans, frac, vis);
		return ans;
	}
};

int main() {
	int n, k; cin >> n >> k;
	Solution sol;
	cout << sol.getPermutation(n, k) << endl;
	return 0;
}
