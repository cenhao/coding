/*
 * Question: given a string, encode it with form:
 * k[encoded_string], where the *encoded_string* inside the square
 * brackets is being repeated exactly *k* times.
 *
 * So that the length of the encoded string is the shortest.
 * length(string) <= 160
 *
 * Input: "aaa"
 * Output: "aaa"
 *
 * Input: "aaaaa"
 * Output: "5[a]"
 *
 * Input: "aaaaaaaaaa"
 * Output: "10[a]"
 *
 * Input: "aabcaabcd"
 * Output: "2[aabc]d"
 *
 * Input: "abbbabbbcabbbabbbc"
 * Output: "2[2[abbb]c]"
 *
 * This is a great DP + string problem.
 * First, we need to calculate the given s.substr(i, j), the maximum
 * time it can repeat.
 *
 * Then use this information to perform a DP like the minimum matrix
 * multiplication.
 */
#include <cstring>
#include <iostream>
#include <string>
using namespace std;

class Solution {
	public:
	const static int MAXL = 160;
	int mul[MAXL][MAXL];
	int len[MAXL][MAXL];
	int dp[MAXL][MAXL];
	int pick[MAXL][MAXL];
	string encode(string s) {
		for (int i=0, end=s.length(); i<end; ++i) {
			for (int j=0, jend=end-i; j<jend; ++j) {
				mul[i][j] = 1; len[i][j] = j + 1;
			}
		}

		for (int i=0, end=s.length(); i<end; ++i) {
			for (int j=0, jend=end-i; j<jend; ++j) {
				for (int k=2; (j+1)*k+i-1<end; ++k) {
					bool match = true;
					int start = i + (k-1) * (j+1);
					for (int l=0; l<=j; ++l) {
						if (s[i+l] != s[start+l]) {
							match = false;
							break;
						}
					}

					if (match) {
						int idx = (j+1) * k - 1;
						int v = getLength(mul[i][idx], len[i][idx]);
						int vv = getLength(k, j+1);
						if (vv < v) {
							mul[i][idx] = k; len[i][idx] = j + 1;
						}
					} else {
						break;
					}
				}
			}
		}

		for (int i=0, end=s.length(); i<end; ++i) {
			for (int j=0, jend=end-i; j<jend; ++j) {
				dp[j][i] = mul[j][i] == 1 ?
					len[j][i] : getLength(mul[j][i], dp[j][len[j][i]-1]);
				pick[j][i] = 0;
				for (int k=1; k<i; ++k) {
					if (dp[j][i] > dp[j][k] + dp[j+k+1][i-k-1]) {
						dp[j][i] = dp[j][k] + dp[j+k+1][i-k-1];
						pick[j][i] = k;
					}
				}
			}
		}

		string ans = "";
		process(0, s.length()-1, ans, s);
		return ans;
	}

	void process(int start, int length, string &ans, string &s) {
		static char buff[10];
		int k = pick[start][length];
		if (k == 0) {
			if (mul[start][length] == 1) {
				ans += s.substr(start, len[start][length]);
			} else {
				sprintf(buff, "%d", mul[start][length]);
				ans += buff;
				ans += "[";
				process(start, len[start][length]-1, ans, s);
				ans += "]";
			}
		} else {
			process(start, k, ans, s);
			process(start+k+1, length-k-1, ans, s);
		}
	}

	inline static int getCost(int n) {
		return (n < 10) ? 1 : ((n < 100) ? 2 : 3);
	}

	inline static int getLength(int m, int l) {
		return (m == 1) ? l : getCost(m) + 2 + l;
	}
};

int main() {
	string in; cin >> in;
	Solution sol;
	cout << sol.encode(in) << endl;
	return 0;
}
