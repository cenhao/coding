/*
ID: cenhao11
PROG: fracdec
LANG: C++11
*/

#include <stdio.h>
#include <string.h>
#include <vector>
using namespace std;

#define MAXN 1000000
int firstAppear[MAXN];

int main() {
	freopen("fracdec.in", "r", stdin);
	freopen("fracdec.out", "w", stdout);
	int n, d;

	scanf("%d %d", &n, &d);
	int intPart = n / d;
	int remainder = n % d;
	memset(firstAppear, -1, sizeof(firstAppear));
	vector<int> vec;

	while (firstAppear[remainder] == -1 && remainder > 0) {
		firstAppear[remainder] = vec.size();
		remainder *= 10;
		vec.push_back(remainder / d);
		remainder %= d;
	}

	int loopStart = remainder == 0 ? -1 : firstAppear[remainder];
	if (vec.size() <= 0) { vec.push_back(0); }

	int printed;
	printed = printf("%d.", intPart);

	for (int i=0, size=vec.size(); i<size; ++i) {
		if (i == loopStart) {
			printf("(");
			if (++printed == 76) {
				printf("\n");
				printed = 0;
			}
		}
		printf("%d", vec[i]);
		if (++printed == 76) {
			printf("\n");
			printed = 0;
		}
	}

	if (loopStart != -1) {
		printf(")");
		if (++printed == 76) {
			printf("\n");
			printed = 0;
		}
	}

	if (printed > 0) { printf("\n"); }
	return 0;
}
