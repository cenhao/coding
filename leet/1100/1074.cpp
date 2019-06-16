#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int numSubmatrixSumTarget(vector<vector<int>>& m, int target) {
		int rsz = m.size(), csz = m[0].size();

		int ans = 0;
		for (int s=0; s<csz; ++s) {
			vector<int> csm(rsz, 0);
			for (int e=s; e<csz; ++e) {
				unordered_map<int, int> hm;
				hm[0] = 1;
				int sm = 0; // sum for matrix [i, [s, e]]
				for (int i=0; i<rsz; ++i) {
					csm[i] += m[i][e]; // current sum of [s -> e] in row i
					sm += csm[i];
					int need = sm - target;
					auto it = hm.find(need);
					if (it != hm.end()) { ans += it->second; }
					hm[sm] += 1;
				}
			}
		}

		return ans;
	}
};

int main() {
	int n, m, t; cin >> n >> m >> t;
	vector<vector<int>> mat(n, vector<int>(m));
	for (int i=0; i<n; ++i) {
		for (int j=0; j<m; ++j) { cin >> mat[i][j]; }
	}
	Solution sol;
	cout << sol.numSubmatrixSumTarget(mat, t) << endl;
	return 0;
}
