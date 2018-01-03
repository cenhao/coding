// F(n) = 3*F(n-1) - F(n-2)
//
// Give F(k) where k < n, F(n) = 2*F(n-1) + sum(F(0..n-2))
// Because, if there's a graph with n nodes, the (n+1)-th node
// can be attached by simply attach to node 0 or node n,
// hence 2*F(n-1).
//
// However, that's not the only to add the node n, node n
// can be attached to both 0 and n-1. In this case, there
// mustn't be an edge between 0 and nodes that are reachable
// from node n.
// If no node is connected to node n-1, then F(n-2) (without
// node 0 and node n-1).
// If node n-2 is connected to n-1, then F(n-3) (without
// node 0, n-1, n-2)
// If node n-3 is connected to n-2 and n-2 to n-1, then
// F(n-4)
// With these we have sum(F(0..n-2))
//
// F(n) = 2*F(n-1) + sum(F(0..n-2))
//      = 2*F(n-1) + 2*F(n-2) + sum(F(0..n-3) - F(n-2)
//      = 2*F(n-1) + F(n-1) - F(n-2) = 3*F(n-1) - F(n-2)
//
// fast matrix power
#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

void mul_assign_to_a(int64_t (*a)[2], int64_t (*b)[2]) {
	int64_t tmp[2][2] = { {0, 0}, {0, 0} };
	for (int i=0; i<2; ++i) {
		for (int j=0; j<2; ++j) {
			for (int k=0; k<2; ++k) {
				tmp[i][j] = (tmp[i][j] + a[i][k] * b[k][j]) % MOD;
			}
		}
	}
	for (int i=0; i<2; ++i) {
		for (int j=0; j<2; ++j) { a[i][j] = tmp[i][j]; }
	}
}

int main() {
	int n;
	while (EOF != scanf("%d", &n)) {
		int64_t base[2][2] = { {3, 1}, {-1, 0} };
		int64_t val[2][2] = { {1, 0}, {0, 1} };
		n -= 1;
		while (n > 0) {
			if (n & 1) { mul_assign_to_a(val, base); }
			mul_assign_to_a(base, base);
			n >>= 1;
		}

		while (val[0][0] < 0) { val[0][0] += MOD; }
		printf("%" PRId64 "\n", (val[0][0]) % MOD);
	}

	return 0;
}
