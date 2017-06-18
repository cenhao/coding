#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int dfs(int a, int p, int cnt, vector<int> &list) {
		if (a == 1) { return cnt; }
		for (int i=9; i>1; --i) {
			if (a % i == 0) {
				list[cnt] = i;
				int tmp;
				if ((tmp = dfs(a/i, p*i, cnt+1, list)) != 0) { return tmp; }
			}
		}

		return 0;
	}
	int smallestFactorization(int a) {
		if (a < 10) { return a; }
		vector<int> list(64);
		int cnt = dfs(a, 1, 0, list);
		int64_t ans = 0;
		if (cnt > 0) {
			for (int i=cnt-1; i>=0; --i) {
				ans = ans * 10 + list[i];
			}
		}

		if (ans > 0x7fffffff) { ans = 0; }
		return ans;
	}
};

int main() {
	int n; scanf("%d", &n);
	Solution sol;
	printf("%d\n", sol.smallestFactorization(n));
	return 0;
}
