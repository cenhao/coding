#include <bits/stdc++.h>
using namespace std;

#define MAXN 1000000
int prime[MAXN+1], pcnt;
bool is_prime[MAXN+1];

void get_prime(int n) {
	memset(is_prime, true, sizeof(is_prime));
	pcnt = 0;
	for (int i=2; i<=n; ++i) {
		if (!is_prime[i]) { continue; }
		for (int j=i+i; j<=n; j+=i) { is_prime[j] = false; }
		prime[pcnt++] = i;
	}
}

int main() {
	int n; scanf("%d", &n);
	get_prime(n);
	for (int i=0; i<pcnt; ++i) {
		int d = n - prime[i];
		int l = 0, r = pcnt-1, m;
		while (l <= r) {
			m = (l + r) / 2;
			if (prime[m] > d) {
				r = m - 1;
			} else {
				l = m + 1;
			}
		}

		if (r > 0 && prime[r] + prime[i] == n) {
			printf("%d %d\n", prime[i], prime[r]);
			break;
		}
	}

	return 0;
}
