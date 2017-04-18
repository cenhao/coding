#include <bits/stdc++.h>
using namespace std;

#define MAXN 100000

int ocnt[MAXN+2];

int main() {
	int g; scanf("%d", &g);
	while (g--) {
		ocnt[0] = 2;
		int pos = 0;
		int n; scanf("%d", &n);
		for (int i=0; i<n; ++i) {
			int v; scanf("%d", &v);

			if (v == 0) {
				ocnt[++pos] = 0;
			} else {
				if (ocnt[pos] == 0) {
					ocnt[++pos] = 1;
				} else {
					++ocnt[pos];
				}
			}
		}

		if (ocnt[pos] == 0) {
			ocnt[++pos] = 2;
		} else {
			ocnt[pos] += 2;
		}

		int cnt = 0;
		for (int i=1; i<pos; ++i) {
			if (ocnt[i] < 2 && ocnt[i-1] < 2 && ocnt[i+1] < 2) { ++cnt; }
		}

		printf((cnt & 1) ? "Alice\n" : "Bob\n");
	}

	return 0;
}
