#include <bits/stdc++.h>
using namespace std;

#define MAXN 10000
char coins[MAXN+1];

int main() {
	int n; scanf("%d", &n);
	scanf("%s", coins);
	int sg = 0;
	for (int i=0; i<n; ++i) {
		if (coins[i] == 'H') { sg ^= (i+1); }
	}

	printf("%s\n", sg == 0 ? "Bob" : "Alice");
	return 0;
}
