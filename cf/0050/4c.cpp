#include <bits/stdc++.h>
using namespace std;

char buff[33];

int main() {
	unordered_map<string, int> hm;
	int n; scanf("%d", &n);

	for (int i=0; i<n; ++i) {
		scanf("%s", buff);
		int c = hm[buff]++;
		if (c == 0) {
			printf("OK\n");
		} else {
			printf("%s%d\n", buff, c);
		}
	}

	return 0;
}
