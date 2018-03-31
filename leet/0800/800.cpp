#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int to_int(char a) {
		if (a >= '0' && a <= '9') {
			return a-'0';
		}
		return 10+a-'a';
	}
	string similarRGB(string color) {
		string ret = "#";
		for (int i=0; i<3; ++i) {
			int v = to_int(color[1+i*2]) * 16 + to_int(color[1+i*2+1]);
			int mn = 0x7fffffff, ans;
			for (int i=0; i<16; ++i) {
				int tv = abs(i*16 + i - v);
				if (tv < mn) {
					mn = tv;
					ans = i;
				}
			}

			char c = (ans < 10) ? '0'+ans : 'a'+ans-10;
			ret += c; ret += c;
		}

		return ret;
	}
};

int main() {
	string s; cin >> s;
	Solution sol;
	cout << sol.similarRGB(s) << endl;
	return 0;
}
