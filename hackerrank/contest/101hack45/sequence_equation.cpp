#include <cstdio>
using namespace std;

#define MAXN 50

int mapping[MAXN];

int main() {
	int n; scanf("%d", &n);
	for (int i=0; i<n; ++i) {
		int v; scanf("%d", &v);
		mapping[v-1] = i;
	}

	for (int i=0; i<n; ++i) {
		printf("%d\n", mapping[mapping[i]] + 1);
	}

	return 0;
}
