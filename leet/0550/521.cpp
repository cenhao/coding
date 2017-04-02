#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int findLUSlength(string a, string b) {
		if (a.length() != b.length()) { return max(a.length(), b.length()); }
		for (int i=0; i<a.length(); ++i) {
			if (a[i] != b[i]) { return a.length(); }
		}

		return -1;
	}
};

int main() {
	string a, b; cin >> a >> b;
	Solution sol;
	cout << sol.findLUSlength(a, b) << endl;
	return 0;
}
