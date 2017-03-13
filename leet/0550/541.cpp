#include <algorithm>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
	string reverseStr(string s, int k) {
		if (k == 0) { return s; }
		int start = 0, end = k;
		while (start < s.size()) {
			int l = min(end, (int)s.size()) - start;
			for (int i=start, iend=i+l/2; i<iend; ++i) {
				int ii = start+l-1-(i-start);
				char tmp = s[i];
				s[i] = s[ii];
				s[ii] = tmp;
			}
			start += 2 * k; end += 2 * k;
		}

		return s;
	}
};

int main() {
	string s; int k;
	Solution sol;
	while (cin >> s >> k) {
		cout << sol.reverseStr(s, k) << endl;
	}

	return 0;
}
