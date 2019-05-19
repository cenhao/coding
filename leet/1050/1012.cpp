#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int p(int n, int m) {
		int ret = 1;
		for (int i=n-m+1; i<=n; ++i) { ret *= i; }
		return ret;
	}

	int numDupDigitsAtMostN(int N) {
		vector<bool> vis(10, false);
		string s = to_string(N+1);
		reverse(s.begin(), s.end());
		int len = s.length();
		int sm = 0;
		for (int i=1; i<len; ++i) { sm += 9 * p(9, i-1); }
		for (int i=len-1; i>=0; --i) {
			int v = p(10-len+i, i);
			for (int j=(i==len-1)?'1':'0'; j<s[i]; ++j) {
				if (!vis[j-'0']) { sm += v; }
			}

			if (vis[s[i]-'0']) { break; }
			vis[s[i]-'0'] = true;
		}

		return N - sm;
	}
};

int main() {
	int n; cin >> n;
	Solution sol;
	cout << sol.numDupDigitsAtMostN(n) << endl;
	return 0;
}
