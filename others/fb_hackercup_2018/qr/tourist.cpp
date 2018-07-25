#include <bits/stdc++.h>
using namespace std;

#define MAXK 50
#define MAXSL 20
char names[MAXK][MAXSL+1];

int main() {
	int T; scanf("%d", &T);
	for (int t=1; t<=T; ++t) {
		int n, k;
		int64_t v; scanf("%d%d%" SCNd64 "", &n, &k, &v);
		for (int i=0; i<n; ++i) { scanf("%s", names[i]); }
		int64_t sp = ((v-1) * k) % n;
		vector<int> ans(k);
		for (int i=0; i<k; ++i) { ans[i] = (sp+i) % n; }
		sort(ans.begin(), ans.end());
		printf("Case #%d:", t);
		for (auto a: ans) { printf(" %s", names[a]); }
		printf("\n");
	}

	return 0;
}
