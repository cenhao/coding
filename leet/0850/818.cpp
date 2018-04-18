#include <bits/stdc++.h>
using namespace std;

/*
// bfs
int step[400001][36];
class Solution {
public:
	int racecar(int target) {
		const int poff = 200000, aoff = 18;
		memset(step, -1, sizeof(step));
		step[poff][aoff] = 0;
		queue<pair<int, int>> q;
		q.push(make_pair(poff, aoff));

		int ans;
		while (!q.empty()) {
			auto tmp = q.front(); q.pop();
			int cnt = step[tmp.first][tmp.second];
			if (tmp.first == target+poff) {
				ans = cnt;
				break;
			}
			int a, p = tmp.first;
			// reverse
			if (tmp.second >= 18) {
				a = 17;
			} else {
				a = 18;
			}

			if (step[p][a]<0 || cnt+1<step[p][a]) {
				step[p][a] = cnt+1;
				q.push(make_pair(p, a));
			}

			int mov = (tmp.second>=aoff) ? (1<<(tmp.second-aoff)) : -(1<<(-tmp.second+aoff-1));
			p = tmp.first + mov;
			a = (tmp.second >= aoff) ? tmp.second + 1 : tmp.second-1;
			if (p<0 || p>2*poff || a>=2*aoff || a<0) { continue; }
			if (step[p][a]<0 || cnt+1<step[p][a]) {
				step[p][a] = cnt+1;
				q.push(make_pair(p, a));
			}
		}

		return ans;
	}
};
*/

const static int MAXT = 10000;
class Solution {
public:
	int calc(int t) {
		if (dp[t] >= 0) { return dp[t]; }
		int pw = log2(t);
		if (t == (1<<(pw+1))-1) {
			dp[t] = pw + 1;
		} else {
			int left_move = (1 << (pw+1)) - 1;
			int need = left_move - t;
			dp[t] = pw+1 +1 + calc(need);

			left_move = (1 << pw) - 1;
			for (int i=0; i<pw; ++i) {
				int right_move = (1 << i) - 1;
				dp[t] = min(dp[t], pw+1+i+calc(t-left_move+right_move)+1);
			}
		}

		return dp[t];
	}
	int racecar(int target) {
		memset(dp, -1, sizeof(dp));
		dp[0] = 0;
		return calc(target);
	}
private:
	int dp[MAXT];
};

int main() {
	int t; cin >> t;
	Solution sol;
	cout << sol.racecar(t) << endl;
	return 0;
}
