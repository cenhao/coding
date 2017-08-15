#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int dp[10], sdp[10];
	void init() {
		dp[0] = sdp[0] = 1;
		for (int i=1, base=10; i<10; ++i, base*=10) {
			dp[i] = sdp[i-1] * 8 + base;
			sdp[i] = dp[i] + sdp[i-1];
		}
	}
	int calc(int x) {
		char buff[16];
		snprintf(buff, sizeof(buff), "%d", x);
		int len = strlen(buff);
		reverse(buff, buff+len);
		int cnt = 0;

		for (int i=len-1; i>=0; --i) {
			if (i > 0) {
				int mul = max(0, buff[i]-'0');
				cnt += mul * sdp[i-1];
			} else {
				if (buff[i] == '9') { ++cnt; }
			}

			if (buff[i] == '9') {
				++cnt;
				for (int j=0, pow=1; j<i; ++j, pow*=10) { cnt += pow * (buff[j]-'0'); }
				break;
			}
		}

		return x - cnt;
	}
	int newInteger(int n) {
		init();
		int64_t l = 1, r = 0x7fffffff;
		while (l <= r) {
			int m = (l + r) >> 1;
			int cnt = calc(m);
			if (cnt < n) {
				l = m + 1;
			} else {
				r = m - 1;
			}
		}

		return l;
	}
};

int main() {
	int n;
	while (cin >> n) {
		Solution sol;
		cout << sol.newInteger(n) << endl;
	}
	return 0;
}
