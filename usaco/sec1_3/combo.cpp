/*
ID: cenhao11
PROG: combo
LANG: C++11
*/

#include <stdio.h>
#include <algorithm>
using namespace std;

int main()
{
	freopen("combo.in", "r", stdin);
	freopen("combo.out", "w", stdout);

	int n;
	int dial[2][3];

	while (EOF != scanf("%d", &n)) {
		scanf("%d %d %d", &dial[0][0], &dial[0][1], &dial[0][2]);
		scanf("%d %d %d", &dial[1][0], &dial[1][1], &dial[1][2]);

		int comb = min(5, n);
		comb *= comb * comb * 2; // 2 * pow((1+2*tolerance), nDial)
		int overlap = 1;

		for (int i=0; i<3; ++i) {
			int dist =
				min((dial[0][i]-dial[1][i]+n)%n,(dial[1][i]-dial[0][i]+n)%n);
			if (dist <= 2) { // <= range, full overlap
				overlap *= min(n, 2 * 2 - dist + 1);
			} else if (dist <= 2 * 2) { // <= 2 * range, patial overlap
				overlap *= 2 * 2 - dist + 1;
			} else {
				overlap *= 0;
			}
		}

		printf("%d\n", comb - overlap);
	}

	return 0;
}
