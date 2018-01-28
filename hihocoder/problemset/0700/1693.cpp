#include <bits/stdc++.h>
using namespace std;

#define MAXN 100000
int a[MAXN], b[MAXN];
int cnt[32];

void add_cnt(int v) {
	for (int i=0; (1<<i)<=v; ++i) { if ((1<<i) & v) ++cnt[i]; }
}

void sub_cnt(int v) {
	for (int i=0; (1<<i)<=v; ++i) { if ((1<<i) & v) --cnt[i]; }
}

int64_t merge_sort(int n) {
	int64_t sm = 0;
	for (int i=0; (1<<i)<n; ++i) {
		int step = 1 << (i+1);
		int half = 1 << i;
		for (int j=0; j<n; j+=step) {
			int ls = j, le = min(n, j+half);
			int rs = le, re = min(n, le+half);
			memset(cnt, 0, sizeof(cnt));
			for (int k=ls; k<le; ++k) { add_cnt(a[k]); }
			int cur = ls;
			while (ls < le && rs < re) {
				if (a[ls] <= a[rs]) {
					sub_cnt(a[ls]);
					b[cur++] = a[ls++];
				} else {
					for (int k=0; (1<<k)<=a[le-1]; ++k) {
						if ((1<<k) & a[rs]) {
							sm += int64_t(1<<k) * (le-ls-cnt[k]);
						} else {
							sm += int64_t(1<<k) * cnt[k];
						}
					}
					b[cur++] = a[rs++];
				}
			}
			while (ls < le) { b[cur++] = a[ls++]; }
			while (rs < re) { b[cur++] = a[rs++]; }
			for (int k=j; k<re; ++k) { a[k] = b[k]; }
		}
	}

	return sm;
}

int main() {
	int n; scanf("%d", &n);
	for (int i=0; i<n; ++i) { scanf("%d", &a[i]); }
	int64_t sm = merge_sort(n);
	printf("%" PRId64 "\n", sm);
	return 0;
}
