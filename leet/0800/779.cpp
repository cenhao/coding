#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int kthGrammar(int n, int k) {
		return calc(n, k -1);
	}
	int calc(int n, int k) {
		if (n == 1) { return 0; }
		int v = calc(n-1, k/2), ret;
		if (v == 0) {
			ret = ((k&1)==1) ? 1 : 0;
		} else {
			ret = ((k&1)==1) ? 0 : 1;
		}

		return ret;
	}
};

int main() {
	int n, k; cin >> n >> k;
	Solution sol;
	cout << sol.kthGrammar(n, k) << endl;
	return 0;
}
