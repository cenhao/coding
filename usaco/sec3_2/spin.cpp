/*
ID: cenhao11
PROG: spin
LANG: C++11
*/

/* A important fact is that no matter what the speed is, after 360s
 * the wheel will always returns to the original state, as (speed*360) % 360 = 0
 * Hence the problem can be solved by simply enumerating through all the time,
 * for each time, to check if there's light passing through cost O(5*360) as all 
 * the wedges in a wheel together can be at most 360.
 * So in the worst case scenario, the time complexity will be O(5*360*360) -> O(n^2)
 */

#include <stdio.h>
#include <string.h>

#define MAXN 5
#define MAXW 5
#define MOD 360

int speed[MAXN];
int wcnt[MAXN];
int wedges[MAXN][MAXW][2];
short through[MOD];

int main() {
	freopen("spin.in", "r", stdin);
	freopen("spin.out", "w", stdout);

	for (int i=0; i<MAXN; ++i) {
		scanf("%d", &speed[i]);
		scanf("%d", &wcnt[i]);
		for (int j=0; j<wcnt[i]; ++j) {
			scanf("%d %d", &wedges[i][j][0], &wedges[i][j][1]);
			wedges[i][j][1] += wedges[i][j][0];
		}
	}

	for (int t=0; t<MOD; ++t) {
		memset(through, 0, sizeof(through));
		for (int i=0; i<MAXN; ++i) {
			int move = (speed[i] * t) % MOD;
			for (int w=0; w<wcnt[i]; ++w) {
				for (int d=wedges[i][w][0]+move, end=wedges[i][w][1]+move; d<=end; ++d) {
					++through[d % MOD];
				}
			}
		}

		for (int i=0; i<MOD; ++i) {
			if (through[i] == MAXN) {
				printf("%d\n", t);
				return 0;
			}
		}
	}

	printf("none\n");
	return 0;
}
