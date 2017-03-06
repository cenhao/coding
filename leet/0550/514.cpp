#include <algorithm>
#include <cstring>
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
	int findRotateSteps(string ring, string key) {
		int dp[101][101];
		memset(dp, -1, sizeof(dp));
		dp[0][0] = 0;

		for (int i=0; i<key.size(); ++i) {
			for (int j=0; j<ring.size(); ++j) {
				if (ring[j] != key[i]) { continue; }
				for (int k=0; k<ring.size(); ++k) {
					if (dp[i][k] < 0) { continue; }
					int a = max(k, j), b = min(k, j);
					int ab = a - b, ba = ring.size() + b - a;
					int p = min(ab, ba) + 1 + dp[i][k];
					if (dp[i+1][j] < 0) {
						dp[i+1][j] = p;
					}
					else {
						dp[i+1][j] = min(dp[i+1][j], p);
					}
				}
			}
		}

		int last = key.size(), ans = 0x7fffffff;
		for (int i=0; i<ring.size(); ++i) {
			if (dp[last][i] < 0) { continue; }
			ans = min(ans, dp[last][i]);
		}

		return ans;
	}
};

int main() {
	string ring, key;
	cin >> ring >> key;
	Solution sol;
	cout << sol.findRotateSteps(ring, key) << endl;
	return 0;
}
