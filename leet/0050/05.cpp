#include <string.h>
#include <iostream>
#include <string>
using namespace std;

class Solution {
	public:
		string longestPalindrome(string s) {
			int len[2003]; memset(len, 0, sizeof(len));
			string tmps = "\r\n";
			for (int i=0; i<s.length(); ++i) { tmps += s[i]; tmps += '\n'; }

			len[1] = 1;
			int center = 1;

			int mx = -1, pos = -1;
			for (int i=2, end=tmps.length(); i<end; ++i) {
				int tc = center;
				while (tc+len[tc] < i || tmps[tc-len[tc]] != tmps[i]) {
					++tc;
					len[tc] = len[center-(tc-center)] < i-tc ?
						len[center-(tc-center)] : i-tc;
				}

				center = tc;
				++len[center];
				if (len[center] > mx) {
					mx = len[center];
					pos = center;
				}
			}

			int start = (pos - mx) / 2;
			int l = (mx - 1) / 2 * 2 + ((mx & 1) ? 0 : 1);

			return s.substr(start, l);
		}
};

int main() {
	string s;
	while (cin >> s) {
		Solution sol;
		cout << sol.longestPalindrome(s) << endl;
	}

	return 0;
}
