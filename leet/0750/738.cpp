#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	bool dfs(string &n, int cur, int pre) {
		if (cur >= n.length()) { return true; }
		if (!dfs(n, cur+1, n[cur])) { --n[cur]; }
		if (n[cur] >= pre) {
			return true;
		} else {
			for (int i=cur; i<n.length(); ++i) {
				n[i] = '9';
			}
			return false;
		}
	}
	int monotoneIncreasingDigits(int N) {
		string n = to_string(N);
		dfs(n, 0, 0);
		int sta = 0;
		while (n[sta] == '0' && sta < n.length()-1) { ++sta; }
		return stoi(n.substr(sta));
	}
};

int main() {
	int n; cin >> n;
	Solution sol;
	cout << sol.monotoneIncreasingDigits(n) << endl;
	return 0;
}
