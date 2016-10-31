/*
 * This problem can be solved using DP, similar to LCS problem.
 * The first step is to break the pattern string into patterns.
 * E.g., a*bbc*.* can be splited into ['a*', 'b', 'b', 'c*', '.*']
 * a character can be matched with a pattern iff: it's the same or the pattern can be repeated 0 times.
 *
 * So the state tranfer equation:
 * dp[i][j] means s[i-1] matches pattern[j-1]
 * dp[i][j] =
 * 1. dp[i-1][j-1] if s[i-1] == patter[j-1] or
 * 2. dp[i-1][j] if pattern[j-1] can be repeated and s[j-2] matches pattern[j-1] too, or
 * 3. dp[i][j-1] if pattern[j-1] can be repeated, this still means they match, but in fact
 * 	s[i-1] matches with pattern[j-2]
 *
 * initialization:
 * dp[0][0] = true;
 * dp[i][0] = false; -> any character must to be matched with a pattern
 * dp[0][j] = true while pattern[j-1] can be repeated, meaning ignore those pattern
 */
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
#include <string.h>

class Solution {
	public:
		struct State {
			char req;
			bool repeat;
		};

		bool isMatch(string s, string p) {
			vector<State> states;
			for (int i=0; i<p.length(); ++i) {
				if (p[i] == '*') {
					states[states.size()-1].repeat = true;
				} else {
					State state = { p[i], false };
					states.push_back(state);
				}
			}

			vector<vector<bool> > dp(s.length() + 1, vector<bool>(states.size() + 1, false));
			dp[0][0] = true;
			for (int i=1; i<=states.size(); ++i) {
				if (!states[i-1].repeat) { break; }
				dp[0][i] = true;
			}

			for (int i=1; i<=s.length(); ++i) {
				for (int i1=1; i1<=states.size(); ++i1) {
					if (states[i1-1].req == s[i-1] || states[i1-1].req == '.') {
						dp[i][i1] = dp[i-1][i1-1];
						if (states[i1-1].repeat && !dp[i][i1]) {
							if (i>1 && (s[i-2] == s[i-1] || states[i1-1].req == '.')) {
								dp[i][i1] = dp[i-1][i1];
							}
						}
					}
					if (states[i1-1].repeat && !dp[i][i1]) {
						dp[i][i1] = dp[i][i1-1];
					}
				}
			}

			return dp[s.length()][states.size()];
		}
};

int main() {
	string s, p;
	while (cin >> s >> p) {
		Solution sol;
		cout << (sol.isMatch(s, p) ? "Y" : "N") << endl;
	}

	return 0;
}

/*
aaa ab*ac*a
ss s*
ss s
ss sss
bbac b*a*ac*
aab b.*
*/
