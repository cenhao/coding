#include <algorithm>
#include <map>
using namespace std;

#include <stdio.h>
#include <string.h>

#define MAXN 1000

char dna[MAXN+1];
bool check[MAXN];
int k;

int process() {
	int len = strlen(dna);
	if (k == len) { return 0; }

	memset(check, 0, sizeof(check));
	int step = len - k, sum = 0, mx, cnt;
	map<char, int> ccnt;

	for (int i=0; i<k; ++i) {
		if (check[i]) { continue; }
		mx = cnt = ccnt['A'] = ccnt['T'] = ccnt['G'] = ccnt['C'] = 0;
		for (int i2=i; i2<len; i2+=step) {
			check[i2] = true;
			++cnt;
			++ccnt[dna[i2]];
			mx = max(mx, ccnt[dna[i2]]);
		}

		sum += cnt - mx;
	}

	return sum;
}

int main() {
	int t;

	for (scanf("%d", &t); t>0; --t) {
		scanf("%s", dna);
		scanf("%d", &k);
		printf("%d\n", process());
	}

	return 0;
}
