#include <bits/stdc++.h>
using namespace std;

#define MAXN 1024
#define MAXB 15
char buff[MAXN+1];
int resp[MAXN+1];
int ans[15];

int main() {
	int T; scanf("%d", &T);
	for (int t=1; t<=T; ++t) {
		int n, b, f; scanf("%d%d%d", &n, &b, &f);
		memset(resp, 0, sizeof(resp));
		for (int i=0; i<5; ++i) {
			string test = "";
			for (int j=0; j<n; ++j) {
				char q = (((j%32) & (1<<i)) >> i) + '0';
				test += q;
			}

			printf("%s\n", test.c_str());
			fflush(stdout);
			scanf("%s", buff);

			for (int j=0; j<n-b; ++j) { resp[j] |= (buff[j]-'0') << i; }
		}

		int nxt = 0, idx = 0;
		for (int i=0; i<n; ++i) {
			int v = i % 32;
			if (v != resp[nxt]) {
				ans[idx++] = i;
			} else {
				++nxt;
			}
		}

		for (int i=0; i<b; ++i) {
			printf("%d%c", ans[i], (i==b-1) ? '\n' : ' ');
		}
		fflush(stdout);

		int verdict;
		scanf("%d", &verdict);
		if (verdict == -1) { break; }
	}

	return 0;
}
