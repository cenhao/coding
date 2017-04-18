#include <bits/stdc++.h>
using namespace std;

int main() {
	int q; scanf("%d", &q);
	while (q--) {
		int n; scanf("%d", &n);
		bool ok = true;
		for (int i=0; i<n; ++i) {
			int v; scanf("%d", &v);
			if (abs(v - i) > 1) { ok = false; }
		}

		printf(ok ? "Yes\n" : "No\n");
	}

	return 0;
}
