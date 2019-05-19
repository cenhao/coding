#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int find(int x, int y, int z, vector<vector<vector<int>>> &dp, const vector<int> &a) {
		if (dp[x][y][z] != -1) { return dp[x][y][z]; }
		if (y+1 == z) { return dp[x][y][z] = a[x] * a[y] * a[z]; }
		int mn = find(y, y+1, z, dp, a) + a[x]*a[y]*a[z];
		for (int i=y+1; i<z; ++i) {
			int v1 = find(x, y, i, dp, a);
			int v2 = find(x, i, z, dp, a);
			mn = min(mn, v1+v2);
		}
		return dp[x][y][z] = mn;
	}

	int minScoreTriangulation(vector<int> &a) {
		int sz = a.size();
		vector<vector<vector<int>>> dp(sz, vector<vector<int>>(sz, vector<int>(sz, -1)));
		return find(0, 1, sz-1, dp, a);
	}
};

int main() {
	int n; cin >> n;
	vector<int> a(n);
	for (int i=0; i<n; ++i) { cin >> a[i]; }
	Solution sol;
	cout << sol.minScoreTriangulation(a) << endl;
	return 0;
}
