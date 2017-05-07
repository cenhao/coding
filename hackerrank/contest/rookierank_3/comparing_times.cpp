#include <bits/stdc++.h>
using namespace std;

int main() {
	int n; scanf("%d", &n);
	for (int i=0; i<n; ++i) {
		char t1[16], t2[16];
		scanf("%s %s", t1, t2);
		int h1, m1, h2, m2;
		char ap1[4], ap2[4];
		sscanf(t1, "%d:%d%s", &h1, &m1, ap1);
		sscanf(t2, "%d:%d%s", &h2, &m2, ap2);
		h1 %= 12; h2 %= 12;
		bool res = (ap1[0] == ap2[0] ?
			(h1 == h2 ? m1 < m2 : (h1 < h2)) :
			ap1[0] < ap2[0]);
		printf(res ? "First\n" : "Second\n");
	}

	return 0;
}
