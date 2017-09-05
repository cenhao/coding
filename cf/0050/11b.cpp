/*
 * Let's consider jumping backward on i-th jump as -i.
 * Then jumping back at the i-th jump is equivalent to
 * sum(1..n) - 2 * i, and the whole takes n step.
 *
 * So jumping back is always an even number, and we have
 * 1 to n to select as a backward jumping.
 *
 * It's not very hard to realize that the whole jumping only
 * requires one backward jump to achieve any number.
 *
 * And as the backward is always even number, hence
 * there're two things to achieve to make any number:
 * 1. make sure the sum is no less than the target.
 * 2. if the sum is no less than the target, then the value should
 * be even or odd depending on the target, as jumping back is even.
 */
#include <bits/stdc++.h>
using namespace std;

int main() {
	int x; scanf("%d", &x);
	x = abs(x);
	int n = (-1+sqrt(1 + 8LL*x)) / 2;
	if (n*(n+1)/2 < x) { ++n; }
	while (((n*(n+1)/2) & 1) != (x & 1)) { ++n; }
	printf("%d\n", n);
	return 0;
}
