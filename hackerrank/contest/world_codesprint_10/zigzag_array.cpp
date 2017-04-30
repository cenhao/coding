#include <bits/stdc++.h>
using namespace std;

#define MAXN 100
int a[MAXN];

int main() {
	int n; scanf("%d", &n);
	for (int i=0; i<n; ++i) { scanf("%d", &a[i]); }

	int state = 0, ans = 0;
	for (int i=1; i<n; ++i) {
		int tmp_state = (a[i] == a[i-1]) ? state : ((a[i] > a[i-1]) ? 1 : -1);
		if (tmp_state == state) {
			++ans;
		} else {
			state = tmp_state;
		}
	}

	printf("%d\n", ans);
	return 0;
}
