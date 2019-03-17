#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int dfs(const string &s, const vector<string> &d, int last, int pos) {
		if (pos >= s.length()) { return 1; }
		int ret = 0;
		for (int i=0, sz=d.size(); i<sz; ++i) {
			if (d[i][0] < s[pos]) {
				ret += last;
			} else {
				if (d[i][0] == s[pos]) { ret += dfs(s, d, last/sz, pos+1); }
				break;
			}
		}

		return ret;
	}

	int atMostNGivenDigitSet(vector<string>& d, int N) {
		string s = to_string(N);
		int sz = d.size(), len = s.length();
		int last = 1, base = 0;
		for (int i=0; i<len-1; ++i) {
			last *= sz;
			base += last;
		}
		return dfs(s, d, last, 0) + base;
	}
};

int main() {
	int n, m;
	cin >> n >> m;
	vector<string> d(m);
	for (int i=0; i<m; ++i) { cin >> d[i]; }
	Solution sol;
	cout << sol.atMostNGivenDigitSet(d, n) << endl;
	return 0;
}
