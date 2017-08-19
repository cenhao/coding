#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int dfs(vector<vector<int>> &vcnt, vector<bool> &cvis, vector<bool> &dvis, vector<bool> &rdvis, int start, int n) {
		if (start == n) { return 1; }
		int ans = 0;
		for (int i=0; i<n; ++i) {
			int didx = start + i, rdidx = n-1+i-start;
			if (cvis[i] || dvis[didx] || rdvis[rdidx]) { continue; }
			cvis[i] = dvis[didx] = rdvis[rdidx] = true;
			ans += dfs(vcnt, cvis, dvis, rdvis, start+1, n);
			cvis[i] = dvis[didx] = rdvis[rdidx] = false;
		}
		return ans;
	}
	int totalNQueens(int n) {
		vector<vector<int>> vcnt(n, vector<int>(n, 0));
		// vector<bool> rvis(n, false); // not necessary
		vector<bool> cvis(n, false);
		vector<bool> dvis(2*n-1, false);
		vector<bool> rdvis(2*n-1, false);
		return dfs(vcnt, cvis, dvis, rdvis, 0, n);
	}
};

int main() {
	int n; cin >> n;
	Solution sol;
	cout << sol.totalNQueens(n) << endl;
	return 0;
}
