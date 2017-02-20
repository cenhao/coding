#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int go(int cur, vector<bool> &vis, int N) {
		if (cur == N) { return 1; }

		int sum = 0;
		for (int i=0; i<N; ++i) {
			if (!vis[i]) {
				if ((cur+1) % (i+1) != 0 && (i+1) % (cur+1) != 0) { continue; }
				vis[i] = true;
				sum += go(cur+1, vis, N);
				vis[i] = false;
			}
		}

		return sum;
	}
	int countArrangement(int N) {
		vector<bool> vis(N, false);
		return go(0, vis, N);
	}
};

int main() {
	int n; cin >> n;
	Solution sol;
	cout << sol.countArrangement(n) << endl;
	return 0;
}
