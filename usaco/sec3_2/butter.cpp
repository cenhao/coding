/*
ID: cenhao11
PROG: butter
LANG: C++11
*/

/*
 * At the beginning I wrote the dijstra wrong... Failing a lot of times...
 * As we only have limited number of edges, so dijstra with head would be
 * fast enough to calculate the shortest path between any two points,
 * then with values we can calculate the cost but enumerating the each point
 * as source.
 * Time complexity is O(n^2logn).
 * After reading the solution in usaco, I realize that I can only calculte
 * the points with cow for shortest path, cutting the time complexity to
 * O(cnlogn)
 */

#include <stdio.h>
#include <string.h>
#include <queue>
using namespace std;

#define MAXP 800

int ecnt[MAXP+1];
int edges[MAXP+1][MAXP][2];
int sp[MAXP+1];
int ccnt[MAXP+1];

class Item {
	public:
		int v;
		int l;
		bool operator <(const Item &item) const {
			return l > item.l;
		}
};

int calcDist(int src, int p) {
	memset(sp, 0x7f, sizeof(sp));
	sp[src] = 0;
	priority_queue<Item> q;
	Item item;
	item.v = src; item.l = 0;
	q.push(item);
	int cnt = 0;

	while (cnt < p && !q.empty()) {
		item = q.top();
		q.pop();
		if (item.l > sp[item.v]) { continue; }
		++cnt;

		Item tmp;
		for (int j=0; j<ecnt[item.v]; ++j) {
			tmp.v = edges[item.v][j][0];
			tmp.l = item.l + edges[item.v][j][1];

			if (sp[tmp.v] > tmp.l) {
				sp[tmp.v] = tmp.l;
				q.push(tmp);
			}
		}
	}

	int sum = 0;
	for (int i=1; i<=p; ++i) {
		sum += sp[i] * ccnt[i];
	}

	return sum;
}

int main() {
	freopen("butter.in", "r", stdin);
	freopen("butter.out", "w", stdout);

	int n, p, c;
	scanf("%d%d%d", &n, &p, &c);
	memset(ccnt, 0, sizeof(ccnt));
	memset(ecnt, 0, sizeof(ecnt));
	for (int i=0; i<n; ++i) {
		int cow;
		scanf("%d", &cow);
		++ccnt[cow];
	}
	for (int i=0; i<c; ++i) {
		int a, b, l;
		scanf("%d %d %d", &a, &b, &l);
		edges[a][ecnt[a]][0] = b;
		edges[a][ecnt[a]][1] = l;
		++ecnt[a];
		edges[b][ecnt[b]][0] = a;
		edges[b][ecnt[b]][1] = l;
		++ecnt[b];
	}

	int mn = 0x7fffff00;
	for (int i=1; i<=p; ++i) {
		int tmp = calcDist(i, p);
		mn = (mn > tmp) ? tmp : mn;
	}

	printf("%d\n", mn);
	return 0;
}
