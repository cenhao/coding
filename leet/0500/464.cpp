#include <cstring>
#include <iostream>
using namespace std;

class Solution {
	public:
	int dp[1049000];
	int target;
	int mxi;
	bool canIWin(int maxChoosableInteger, int desiredTotal) {
		target = desiredTotal;
		mxi = maxChoosableInteger;
		memset(dp, 0, sizeof(int) * (1<<maxChoosableInteger));

		for (int i=1; i<=maxChoosableInteger; ++i) {
			if (check((1<<(i-1)), i) == 1) {
				return true;
			}
		}

		return false;
	}

	int check(int state, int sum) {
		if (dp[state] != 0) {
			return dp[state];
		}

		if (sum >= target) {
			dp[state] = 1;
			return 1; // win
		}

		dp[state] = 2; // unknown
		bool anyw = false;
		bool anyl = false;
		for (int i=1; i<=mxi; ++i) {
			if ((state & (1 << (i-1))) == 0) {
				int res = check(state | (1<<(i-1)), sum + i);
				if (res == 1) {
					anyw = true;
				} else if (res == 3) {
					anyl = true;
				}
			}
		}

		if (anyw || anyl) { dp[state] = anyw ? 3 : 1; }
		return dp[state];
	}
};

int main() {
	int a, b;
	cin >> a >> b;
	Solution sol;
	cout << sol.canIWin(a, b) << endl;
	return 0;
}
