/*
ID: cenhao11
PROG: milk
LANG: C++11
*/

#include <stdio.h>
#include <algorithm>
using namespace std;

#define MAXM 5005

struct MilkOffer {
	int price;
	int unit;
} mo[MAXM];

int main()
{
	freopen("milk.in", "r", stdin);
	freopen("milk.out", "w", stdout);

	int n, m;

	while (EOF != scanf("%d %d\n", &n, &m)) {
		for (int i=0; i<m; ++i) { scanf("%d %d", &mo[i].price, &mo[i].unit); }
		sort(mo, mo + m, [](const MilkOffer& mo1, const MilkOffer& mo2) { return (mo1.price < mo2.price); });

		int pay = 0;
		for (int i=0; n > 0; ++i) {
			int take = (n < mo[i].unit) ? n : mo[i].unit;
			n -= take;
			pay += mo[i].price * take;
		}

		printf("%d\n", pay);
	}

	return 0;
}
