/*
ID: cenhao11
PROG: shopping
LANG: C++11
*/

/* solved by treating this as a 5-dimension back pack dp....
 * Ended up with super ugly code...
 * The offical answer was treating this as a shortest path
 */

#include <stdio.h>
#include <string.h>
#include <map>
using namespace std;

#define MAXK 5
#define MAXS 99

struct Offer {
	int requirement[MAXK];
	int price;
} offers[MAXS];

int dp[MAXK+1][MAXK+1][MAXK+1][MAXK+1][MAXK+1];
map<int, int> codeMap;
int price[MAXK];
int need[MAXK];

void process(int s) {
	for (int i=0; i<=MAXK; ++i) {
		int p0 = price[0] * i;
		for (int j=0; j<=MAXK; ++j) {
			int p1= price[1] * j;
			for (int k=0; k<=MAXK; ++k) {
				int p2 = price[2] * k;
				for (int l=0; l<=MAXK; ++l) {
					int p3 = price[3] * l;
					for (int m=0; m<=MAXK; ++m) {
						int p4 = price[4] * m;
						int sum = p0 + p1 + p2 + p3 + p4;
						dp[i][j][k][l][m] = sum;
					}
				}
			}
		}
	}

	for (int o=0; o<s; ++o) {
		for (int i=0; i<=MAXK; ++i) {
			for (int j=0; j<=MAXK; ++j) {
				for (int k=0; k<=MAXK; ++k) {
					for (int l=0; l<=MAXK; ++l) {
						for (int m=0; m<=MAXK; ++m) {
							int ii = i - offers[o].requirement[0];
							int jj = j - offers[o].requirement[1];
							int kk = k - offers[o].requirement[2];
							int ll = l - offers[o].requirement[3];
							int mm = m - offers[o].requirement[4];
							if (ii >= 0 && jj >= 0 &&
									kk >= 0 && ll >= 0 && mm >= 0) {
								if (dp[ii][jj][kk][ll][mm] + offers[o].price < dp[i][j][k][l][m]) {
									dp[i][j][k][l][m] = dp[ii][jj][kk][ll][mm] + offers[o].price;
								}
							}
						}
					}
				}
			}
		}
	}
}

int main() {
	freopen("shopping.in", "r", stdin);
	freopen("shopping.out", "w", stdout);
	memset(need, 0, sizeof(need));
	int s, b, ccnt = 0;
	scanf("%d", &s);

	for (int i=0; i<s; ++i) {
		scanf("%d", &b);
		int c, n;

		for (int j=0; j<b; ++j) {
			scanf("%d %d", &c, &n);
			auto it = codeMap.find(c);
			int id;

			if (it == codeMap.end()) {
				id = ccnt++;
				codeMap.insert(pair<int, int>(c, id));
			} else {
				id = it->second;
			}

			offers[i].requirement[id] = n;
		}

		scanf("%d", &offers[i].price);
	}

	memset(dp, -1, sizeof(dp));
	dp[0][0][0][0][0] = 0;

	scanf("%d", &b);
	for (int i=0; i<b; ++i) {
		int c, k, p;
		scanf("%d %d %d", &c, &k, &p);
		int id;
		auto it = codeMap.find(c);
		if (it == codeMap.end()) {
			id = ccnt++;
			codeMap.insert(pair<int, int>(c, id));
		} else {
			id = it->second;
		}
		price[id] = p;
		need[id] = k;
	}

	process(s);

	printf("%d\n", dp[need[0]][need[1]][need[2]][need[3]][need[4]]);
	return 0;
}

