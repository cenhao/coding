#include <bits/stdc++.h>
using namespace std;

int main() {
	int a, b;
	char c;
	scanf("%d%c%d", &a, &c, &b);
	printf("%d\n", c == '+' ? a+b : a-b);
	return 0;
}
