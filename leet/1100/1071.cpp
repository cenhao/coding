#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	bool check(string &t, string &s1, string &s2) {
		int len = t.length();
		for (int i=0; i<s1.length() || i<s2.length(); i+=len) {
			for (int j=0; j<len; ++j) {
				if (i+j < s1.length() && t[j] != s1[i+j]) { return false; }
				if (i+j < s2.length() && t[j] != s2[i+j]) { return false; }
			}
		}

		return true;
	}

	string gcdOfStrings(string str1, string str2) {
		string ans = "";
		int len1 = str1.length(), len2 = str2.length();
		int len = min(len1, len2);
		string tmp;
		for (int i=0; i<len; ++i) {
			tmp += str1[i];
			int tlen = tmp.length();
			if ((len1%tlen == 0) && (len2%tlen == 0)) {
				if (check(tmp, str1, str2)) {
					ans = tmp;
				}
			}
		}

		return ans;
	}
};

int main() {
	string s1, s2; cin >> s1 >> s2;
	Solution sol;
	cout << sol.gcdOfStrings(s1, s2) << endl;
	return 0;
}
