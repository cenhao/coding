#include <bits/stdc++.h>
using namespace std;

int howMuchToAsk(int c, int p) {
	const static int bill[6] = { 20, 50, 100, 200, 500, 1000 };
	int ans = -1;
	for (int i=0; i<10 && ans==-1; ++i) {
		int ret = p + i - c;
		for (auto b: bill) {
			ans = (b == ret) ? i : ans;
		}
	}

	return ans;
}

int main() {
	int t; scanf("%d", &t);
	while (t--) {
		int c, p; scanf("%d%d", &c, &p);
		printf("%d\n", howMuchToAsk(c, p));
	}
	return 0;
}
