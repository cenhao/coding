#include <string>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
	public:
		string longestCommonPrefix(vector<string>& strs) {
			if (strs.size() == 0) { return ""; }

			bool stop = false;
			int len;
			for (len=0; !stop; ++len) {
				if (len >= strs[0].length()) {
					++len; // to compensate the ++len
					break;
				}
				char c = strs[0][len];
				for (int i=1, end=strs.size(); i<end; ++i) {
					if (strs[i].length() <= len || strs[i][len] != c) {
						stop = true;
						break;
					}
				}
			}

			return strs[0].substr(0, len-1);
		}
};

int main() {
	int n;
	while (cin >> n) {
		vector<string> strs;
		string s;
		for (int i=0; i<n; ++i) {
			cin >> s;
			strs.push_back(s);
		}

		Solution sol;
		cout << sol.longestCommonPrefix(strs) << endl;
	}

	return 0;
}
