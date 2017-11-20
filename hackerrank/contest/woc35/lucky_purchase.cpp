#include <bits/stdc++.h>
using namespace std;

int main() {
	int n; scanf("%d", &n);
	char name[16], pick[16] = "-1", str_price[16];
	int mn = 0x7ffffff0;
	for (int i=0; i<n; ++i) {
		int p; scanf("%s %d", name, &p);
		snprintf(str_price, sizeof(str_price), "%d", p);
		int len = strlen(str_price);

		int fcnt, scnt, ocnt; fcnt = scnt = ocnt = 0;
		for (int j=0; j<len; ++j) {
			if (str_price[j] == '4') {
				++fcnt;
			} else if (str_price[j] == '7') {
				++scnt;
			} else {
				++ocnt;
			}
		}

		if (ocnt > 0 || fcnt != scnt) { continue; }
		if (p < mn) {
			mn = p;
			strcpy(pick, name);
		}
	}

	printf("%s\n", pick);
	return 0;
}
