#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	string longestPrefix(string s) {
		int len = s.length();
		if (len <= 1) { return ""; }
		vector<int> fail(len, -1);
		for (int i=1, fp=-1; i<len; ++i) {
			while (fp!=-1 && s[fp+1]!=s[i]) {
				fp = fail[fp];
			}
			if (s[fp+1] == s[i]) {
				fp = fail[i] = fp+1;
			}
		}

		if (fail[len-1] == -1) { return ""; }
		return s.substr(0, fail[len-1]+1);
	}
};

int main() {
	string s; cin >> s;
	Solution sol;
	cout << sol.longestPrefix(s) << endl;
	return 0;
}
