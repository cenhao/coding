/*
 * Say s2 can be constructed from s1, if s2 can be formed by removing some characters from s1.
 * E.g.: s1 = "ACCDEB", S2 = "ADB".
 * Given s1, n1, s2, n2, let SN1 = s1 repeats n1 times, SN2 = s2 repeats n2 times
 * Length(s1), length(s2) <= 100, n1, n2 <= 10^6
 * what is the maximum M, so that SN2M = SN2 repeats M times, and SN2M can be constructed
 * from SN1
 *
 * The idea is that, we calculate the # of characters that need to go through to construct s2,
 * if start from the i-th character of s1.
 * With this, the # of characters that need to go through if we want to construct s2 * 2^k
 * as we now have s2 * 2^0
 *
 * In the end the maximum repeation of s2 can be calculated, then divide this maximum with
 * n2 is M
 */

#include <cstring>
#include <iostream>
#include <string>
using namespace std;

class Solution {
	public:
	const static int MAXP = 28; // 2^27 > 10^8
	const static int MAXL = 100;
	int dp[MAXP][MAXL];

	int getMaxRepetitions(string s1, int n1, string s2, int n2) {
		memset(dp, 0, sizeof(dp));
		int len1 = s1.length(), len2 = s2.length();

		for (int i=0; i<len1; ++i) {
			int cnt = 0, cur = i;
			for (int i1=0; i1<len2; ++i1) {
				int tmp = cnt + len1;
				while (cnt < tmp && s1[cur] != s2[i1]) {
					++cnt; cur = (cur+1) % len1;
				}

				if (s1[cur] != s2[i1]) { return 0; }
				++cnt; cur = (cur+1) % len1;
			}

			dp[0][i] = cnt;
		}

		int pw = 1;
		while (true) {
			for (int i=0; i<len1; ++i) {
				dp[pw][i] = dp[pw-1][i] + dp[pw-1][(i+dp[pw-1][i])%len1];
			}

			if (dp[pw][0] >= n1 * len1) { break; }
			++pw;
		}

		int cnt = 0, cur = 0, sum = 0;
		for (int i=pw; i>=0; --i) {
			if ((cnt + dp[i][cur]) > n1 * len1) { continue; }
			cnt += dp[i][cur];
			cur = cnt % len1;
			sum += 1 << i;
		}

		return sum / n2;
	}
};

int main() {
	int n1, n2;
	string s1, s2;
	cin >> s1 >> n1 >> s2 >> n2;
	Solution sol;
	cout << sol.getMaxRepetitions(s1, n1, s2, n2) << endl;
	return 0;
}
