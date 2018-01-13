#include <bits/stdc++.h>
using namespace std;

#define MAXN 100

char vs[MAXN][MAXN+1];
int v[MAXN][MAXN+1];
int idx[MAXN];

int main() {
	int n; scanf("%d", &n);
	memset(v, 0, sizeof(v));
	for (int i=0; i<n; ++i) {
		scanf("%s", vs[i]);
		int len = strlen(vs[i]);
		++v[i][0];
		idx[i] = i;
		for (int j=0; j<len; ++j) {
			if (vs[i][j] == '.') {
				++v[i][0];
			} else {
				v[i][v[i][0]] = v[i][v[i][0]]*10 + vs[i][j]-'0';
			}
		}
	}
	sort(idx, idx+n, [](int i1, int i2) {
		for (int a=1; a<=::v[i1][0] && a<=::v[i2][0]; ++a) {
			if (::v[i1][a] != ::v[i2][a]) { return ::v[i1][a] < ::v[i2][a]; }
		}

		return ::v[i1][0] < ::v[i2][0];
	});

	for (int i=0; i<n; ++i) { printf("%s\n", vs[idx[i]]); }
	return 0;
}
