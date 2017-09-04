#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int flipLights(int n, int m) {
		if (n == 0) { return 1; }
		int end = (n == 1) ? 2 : ((n == 2) ? 4 : 8);
		int mask = end - 1;
		int op[4] = { 7, 2, 5, 1 };

		bool possible[8][2];
		memset(possible, false, sizeof(possible));
		possible[mask][1] = true;
		for (int i=0; i<m; ++i) {
			int cur = i & 1, pre = (i+1) & 1;
			for (int j=0; j<end; ++j) { possible[j][cur] = false; }
			for (int j=0; j<end; ++j) {
				if (!possible[j][pre]) { continue; }
				for (int k=0; k<4; ++k) {
					int idx = (j^op[k]) & mask;
					possible[idx][cur] = true;
				}
			}
		}

		int cnt = 0;
		int cur = (m-1) & 1;
		for (int i=0; i<end; ++i) { if (possible[i][cur]) { ++cnt; } }
		return cnt;
	}
};

int main() {
	int n, m; cin >> n >> m;
	Solution sol;
	cout << sol.flipLights(n, m) << endl;
	return 0;
}

/*
 * // the O(1) approach
 * class Solution {
 * public:
 *     int flipLights(int n, int m) {
 * 		   if (m == 0 || n == 0) return 1;
 *         if (n == 1) return 2;
 *         if (n == 2) return m == 1? 3:4;
 *         if (m == 1) return 4;
 *         return m == 2? 7:8;
 *     }
 * };
 */
