#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
	string pushDominoes(string d) {
		int last = -1;
		char lc = '.';
		for (int i=0; i<d.length(); ++i) {
			if (d[i] == '.') {
				continue;
			} else if (d[i] == 'L') {
				if (lc == 'R') {
					int l = last, r = i;
					while (l < r) {
						d[l++] = 'R';
						d[r--] = 'L';
					}
					if (l == r) { d[l] = '.'; }
				} else {
					for (int j=last+1; j<=i; ++j) {
						d[j] = 'L';
					}
				}
				last = i;
				lc = 'L';
			} else {
				if (lc == 'R') {
					for (int j=last; j<i; ++j) { d[j] = 'R'; }
				}
				last = i;
				lc = 'R';
			}
		}
		if (lc == 'R') {
			for (int i=last+1; i<d.length(); ++i) { d[i] = 'R'; }
		}
		return d;
	}
};

int main() {
	string in; cin >> in;
	Solution sol;
	cout << sol.pushDominoes(in) << endl;
	return 0;
}
