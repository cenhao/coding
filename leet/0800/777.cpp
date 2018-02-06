#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canTransform(string start, string end) {
		int slen = start.length(), elen = end.length();
		if (slen != elen) { return false; }
		int pos = 0;
		for (int i=0; i<elen; ++i) {
			if (end[i] == 'X') { continue; }
			if (end[i] == 'R') {
				while (pos<slen && start[pos] == 'X') { ++pos; }
				if (pos>=slen || start[pos]=='L' || pos>i) { return false; }
			} else {
				while (pos<slen && start[pos] == 'X') { ++pos; }
				if (pos>=slen || start[pos]=='R' || pos<i) { return false; }
			}
			++pos;
		}

		for (int i=pos; i<slen; ++i) {
			if (start[pos] != 'X') { return false; }
		}

		return true;
    }
};

int main() {
	string s, e; cin >> s>> e;
	Solution sol;
	cout << sol.canTransform(s, e) << endl;
	return false;
}
