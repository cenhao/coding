#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
	static int64_t toInt64(const string &n) {
		int64_t val = 0;
		for (int i=0; i<n.length(); ++i) { val = val*10 + n[i]-'0'; }
		return val;
	}

	static string toString(int64_t v) {
		if (v == 0) { return string("0"); }
		string n;
		while (v > 0) { n += '0' + v % 10; v /= 10; }
		reverse(n.begin(), n.end());
		return n;
	}

	static string adjust(const string &n, int pos, int mode) {
		int len = n.length();
		int64_t adj = 1;
		for (int i=n.length()-1; i>pos; --i) { adj *= 10; }

		char c[2] = { '0', '9' };
		int sign[2] = { 1, -1 };
		string tmp = n;
		for (int i=pos+1; i<len; ++i) { tmp[i] = c[mode]; }
		int64_t v = toInt64(tmp) + adj * sign[mode];
		return toString(v);
	}

	static string gen(const string &n) {
		int len = n.length();
		string tmp = n;
		for (int i=0, end=len/2; i<end; ++i) { tmp[len-1-i] = n[i]; }
		return tmp;
	}

public:
	string nearestPalindromic(string n) {
		int len = n.length();
		if (len == 1) {
			--n[0];
			return n;
		}

		string tmp = gen(n), ans;
		if (tmp == n) {
			int r = len / 2;
			int l = r - ((len%2==0) ? 1 : 0);
			if (n[r] == '0') {
				tmp[l] = n[l] + 1; tmp[r] = n[r] + 1;
			} else {
				tmp[l] = n[l] - 1; tmp[r] = n[r] - 1;
			}
		}
		int64_t ntmp = toInt64(tmp), val = toInt64(n), nans;
		ans = tmp; nans = ntmp;
		int64_t mn = abs(nans - val);

		for (int i=0, end=len/2+(len&1); i<end; ++i) {
			for (int j=0; j<2; ++j) {
				tmp = gen(adjust(n, i, j));
				ntmp = toInt64(tmp);
				int64_t diff = abs(ntmp - val);
				if (diff < mn) {
					mn = diff;
					nans = ntmp;
					ans = tmp;
				} else if (diff == mn) {
					if (ntmp < nans) {
						nans = ntmp;
						ans = tmp;
					}
				}
			}
		}

		return ans;
	}
};

int main() {
	string s; cin >> s;
	Solution sol;
	cout << sol.nearestPalindromic(s) << endl;
	return 0;
}
