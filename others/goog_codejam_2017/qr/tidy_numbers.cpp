#include <bits/stdc++.h>
using namespace std;

char nstr[32];

int main() {
	int T; scanf("%d", &T);

	for (int t=1; t<=T; ++t) {
		int64_t n; scanf("%" SCNd64 "", &n);
		snprintf(nstr+1, sizeof(nstr)-sizeof(char), "%" PRId64 "", n);
		nstr[0] = '0';
		for (int i=1, len=strlen(nstr); i<len; ++i) {
			if (nstr[i] < nstr[i-1]) {
				int pos = i-1;
				while (--nstr[pos] < nstr[pos-1]) { --pos; }
				for (int j=pos+1; j<len; ++j) { nstr[j] = '9'; }
			}
		}

		printf("Case #%d: ", t);
		for (int i=0, len=strlen(nstr); i<len; ++i) {
			if (nstr[i] != '0') { printf("%c", nstr[i]); }
		}
		printf("\n");
	}

	return 0;
}
