#include <bits/stdc++.h>
using namespace std;

int s[4];

int dfs(int sum, int cur, int cnt) {
	if (cnt == 2) {
		int ans = 0;
		for (int i=cur; i<4; ++i) {
			if (sum > s[i]) {
				return 2;
			} else if (sum == s[i]) {
				ans = 1;
			}
		}

		return ans;
	}

	int ans = 0;
	for (int i=cur; i<=cnt+1; ++i) {
		ans = max(ans, dfs(sum+s[i], i+1, cnt+1));
	}

	return ans;
}

int main() {
	scanf("%d %d %d %d", &s[0], &s[1], &s[2], &s[3]);
	sort(s, s+4);
	int ans = dfs(0, 0, 0);
	printf("%s\n", (ans) ? (ans == 2 ? "TRIANGLE" : "SEGMENT") : "IMPOSSIBLE");
	return 0;
}
