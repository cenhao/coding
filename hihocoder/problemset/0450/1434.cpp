#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

#define MAXN 100
#define MAXSL 1000

struct Photo {
	char name[MAXSL];
	int n;

	bool operator <(const Photo& p) const {
		int diff = strcmp(name, p.name);

		if (diff == 0) {
			return n < p.n;
		}

		return diff < 0;
	}
} photoes[MAXN];

int main() {
	int n; scanf("%d", &n);
	for (int i=0; i<n; ++i) {
		scanf("%s", photoes[i].name);
		int len = strlen(photoes[i].name);
		int v = 0, base = 1;
		for (int j=len-1; photoes[i].name[j]>='0' && photoes[i].name[j]<='9'; --j) {
			v += (photoes[i].name[j]-'0') * base;
			base *= 10;
			photoes[i].name[j] = 0;
		}
		photoes[i].n = v;
	}

	sort(photoes, photoes+n);

	for (int i=0; i<n; ++i) {
		printf("%s%d\n", photoes[i].name, photoes[i].n);
	}

	return 0;
}
