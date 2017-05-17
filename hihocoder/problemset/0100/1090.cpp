/*
 * 1. Cars will only be slowed down by cars which are ahead
 * 2. Cars won't be slower down by cars with higher speed
 *
 * For each car C, try to find the next car N that's ahead and slower.
 *
 * if the destination of the car ahead dest[N] <= dest[C], it means
 * car C will be affected until N exited.
 * For C, the earliest time C can reach dest[N] is (dest[N] - pos[C]) / v[C]
 * but as C might be affected by N, hence the time will be max((dest[N]-pos[C])/v[C], time[N])
 * where pos is the current position of C, and time[N] is the time N exited.
 * then continue to find the next car N' until C exit.
 *
 * if the destination of the car ahead dest[N] > dest[c], then C will only
 * be affected by N. In this case we can consider N exited at dest[C],
 * and recalculate the time for N to exit at dest[C]
 * Then the time will be max((dest[C]-pos[C])/v[C], calc(N, dest[C]))
 */
#include <bits/stdc++.h>
using namespace std;

#define MAXN 1000

struct Car {
	int s, e, v, id;
	double t;
} cars[MAXN];

double calc_time(int n, int dest) {
	int pos = cars[n].s;
	double time = 0;
	for (int i=n-1; i>=0 && pos < dest; --i) {
		if (cars[i].v >= cars[n].v) { continue; }
		if (cars[i].e <= dest) {
			time = max(cars[i].t, time+double(cars[i].e-pos)/cars[n].v);
			pos = cars[i].e;
		} else {
			time = max(calc_time(i, dest), time+double(dest-pos)/cars[n].v);
			pos = dest;
		}
	}

	time += double(dest-pos) / cars[n].v;
	return time;
}

int main() {
	int n; scanf("%d", &n);
	for (int i=0; i<n; ++i) {
		scanf("%d %d %d", &cars[i].s, &cars[i].e, &cars[i].v);
		cars[i].id = i;
	}

	sort(cars, cars+n, [](const Car &c1, const Car &c2) -> bool {
		return c1.s > c2.s;
	});

	for (int i=0; i<n; ++i) {
		cars[i].t = calc_time(i, cars[i].e);
	}

	sort(cars, cars+n, [](const Car &c1, const Car &c2) ->bool {
		return c1.id < c2.id;
	});

	for (int i=0; i<n; ++i) {
		printf("%.2lf\n", cars[i].t);
	}

	return 0;
}
