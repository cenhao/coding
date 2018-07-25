#include <bits/stdc++.h>
using namespace std;

#define MAXN 100
int p[MAXN*2];
bool show[MAXN+1];

int main() {
	int n; scanf("%d", &n);
	for (int i=0; i<n*2; ++i) { scanf("%d", &p[i]); }
	memset(show, false, sizeof(show));
	int cnt = 0;
	for (int i=0; i<n*2; ++i) {
		if (!show[p[i]]) {
			show[p[i]] = true;
		} else {
			int tmp = i;
			while (p[tmp-1] != p[tmp]) {
				swap(p[tmp-1], p[tmp]);
				++cnt;
				--tmp;
			}
		}
	}

	printf("%d\n", cnt);
	return 0;
}
