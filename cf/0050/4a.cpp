#include <bits/stdc++.h>
using namespace std;

int main() {
	int w; scanf("%d", &w);
	printf((w>2 && !(w&1)) ? "YES\n" : "NO\n");
	return 0;
}
