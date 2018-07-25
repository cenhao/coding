#include <bits/stdc++.h>
using namespace std;

int main() {
	int n; scanf("%d", &n);
	int cnt = 0;
	if (n > 0) {
		cnt += n / 100; n %= 100;
	}
	if (n > 0) {
		cnt += n / 20; n %= 20;
	}
	if (n > 0) {
		cnt += n / 10; n %= 10;
	}
	if (n > 0) {
		cnt += n / 5; n %= 5;
	}
	if (n > 0) { cnt += n; }
	printf("%d\n", cnt);
	return 0;
}
