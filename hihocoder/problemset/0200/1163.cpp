#include <bits/stdc++.h>
using namespace std;

int main() {
	int n; scanf("%d", &n);
	int sta = 0;
	for (int i=0; i<n; ++i) {
		int v; scanf("%d", &v);
		sta ^= v;
	}

	printf("%s", (sta==0) ? "Bob\n" : "Alice\n");
	return 0;
}
