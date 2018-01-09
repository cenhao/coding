#include <bits/stdc++.h>
using namespace std;

int main() {
	int k[3];
	for (int i=0; i<3; ++i) { scanf("%d", &k[i]); }
	sort(k, k+3);
	int cnt[4] = { 0, 0, 0, 0 };
	for (int i=0; i<3; ++i) { if (k[i] <=4 ) { ++cnt[k[i]-1]; } }
	bool ok = (cnt[0] > 0 || cnt[1] > 1 || cnt[2] > 2 || (cnt[3]>1 && cnt[1]>0));
	printf(ok ? "YES\n" : "NO\n");
	return 0;
}
