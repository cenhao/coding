#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

#define MAXS 100000

char in[MAXS+1];
int stack[MAXS >> 1];

struct Pair {
	int l, r;
} pairs[MAXS >> 1];

int main() {
	scanf("%s", in);
	int head = -1;
	int pcnt = 0;

	for (int i=0, end=strlen(in); i<end; ++i) {
		if (in[i] == '(') {
			stack[++head] = i;
		} else {
			pairs[pcnt].l = stack[head--] + 1;
			pairs[pcnt].r = i + 1;
			++pcnt;
		}
	}

	sort(pairs, pairs+pcnt, [](const Pair &p1, const Pair &p2) {
		return p1.l < p2.l;
	});

	for (int i=0; i<pcnt; ++i) { printf("%d %d\n", pairs[i].l, pairs[i].r); }

	return 0;
}
