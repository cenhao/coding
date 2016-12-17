#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

#define MAXS 1000000

char str[MAXS+1];
int ans[MAXS], cnt;

bool is_higher(int cidx, int sidx) {
	if (cidx == 0) { return false; }
	int s1 = sidx-ans[cidx]+1, e1 = sidx+1;
	int s2 = s1-ans[cidx-1], e2 = s1;

	for (int i=0; s1+i<e1 && s2+i<e2; ++i) {
		if (str[s1+i] != str[s2+i]) { return str[s1+i] > str[s2+i]; }
	}

	return ans[cidx] > ans[cidx-1];
}

int main() {
	int t; scanf("%d", &t);
	while (t--) {
		scanf("%s", str);
		cnt = 0;

		for (int i=0, len=strlen(str); i<len; ++i) {
			ans[cnt++] = 1;
			while (is_higher(cnt-1, i)) {
				ans[cnt-2] += ans[cnt-1];
				--cnt;
			}
		}

		for (int i=0; i<cnt; ++i) {
			printf((i==0) ? "%d" : " %d", ans[i]);
		}
		printf("\n");
	}

	return 0;
}
