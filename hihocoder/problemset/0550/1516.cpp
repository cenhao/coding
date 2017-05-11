#include <bits/stdc++.h>
using namespace std;

#define MAXN 16

int bcnt[1<<MAXN]; // # of people on the boat
int tcnt[1<<MAXN][2]; // minimum # of trip
int attack[MAXN];
int block[MAXN];
int id[1<<MAXN];
int d;

#define LB(x) (x & (~(x-1)))

struct QItem { int state, boat; };

void count_boat(int n) {
	bcnt[0] = 0;
	for (int i=1, end=1<<n; i<end; ++i) { bcnt[i] = 1 + bcnt[i&(i-1)]; }
}

void set_id(int n) {
	for (int i=0; i<n; ++i) { id[1<<i] = i; }
}

bool is_valid(int v, int n) {
	int tmp = v;
	while (tmp != 0) {
		int lb = LB(tmp);
		int i = id[lb];
		tmp -= lb;

		if ((v & attack[i]) != 0 && (v & block[i]) == 0) { return false; }
	}

	return true;
}

void bfs(int n, int m) {
	memset(tcnt, -1, sizeof(tcnt));
	tcnt[0][0] = 0;
	QItem cur = { 0, 0 }, tmp;
	queue<QItem> q;
	q.push(cur);

	int full = (1 << n) - 1;

	while (!q.empty()) {
		cur = q.front(); q.pop();
		int people[2] = { (~cur.state) & full, cur.state };
		for (int b=people[cur.boat]; b>0; b=people[cur.boat]&(b-1)) {
			if (bcnt[b] > m || (b & d) == 0) { continue; }
			int new_people[2];
			if (cur.boat == 0) {
				new_people[0] = (people[0] & (~b));
				new_people[1] = (people[1] | b);
			} else {
				new_people[0] = (people[0] | b);
				new_people[1] = (people[1] & (~b));
			}

			if (!is_valid(new_people[0], n) || !is_valid(new_people[1], n) || !is_valid(b, n)) {
				continue;
			}

			tmp.boat = cur.boat ^ 1;
			tmp.state = new_people[1];

			if (tcnt[tmp.state][tmp.boat] == -1) {
				tcnt[tmp.state][tmp.boat] = tcnt[cur.state][cur.boat] + 1;
				q.push(tmp);
			}

			if (tmp.boat == 1 && tmp.state == full) { break; }
		}
	}
}

int main() {
	int n, m; scanf("%d %d", &n, &m);
	count_boat(n);
	set_id(n);
	memset(attack, 0, sizeof(attack));
	memset(block, 0, sizeof(block));
	int a, b, c; scanf("%d %d %d", &a, &b, &c);
	for (int i=0; i<a; ++i) {
		int x, y; scanf("%d %d", &x, &y);
		attack[x] |= 1 << y;
	}
	for (int i=0; i<b; ++i) {
		int x, y; scanf("%d %d", &x, &y);
		block[y] |= 1 << x;
	}

	d = 0; // drives bitmap
	for (int i=0; i<c; ++i) {
		int x; scanf("%d", &x);
		d |= 1 << x;
	}

	bfs(n, m);
	printf("%d\n", tcnt[(1<<n)-1][1]);
	return 0;
}
