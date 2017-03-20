#include <cstdio>
using namespace std;

int main() {
	int n, t; scanf("%d %d", &n, &t);
	int cur = n, add = 0;
	for (int i=1; i<=t; ++i) {
		int take; scanf("%d", &take);
		cur -= take;
		if (cur < 5 && i != t) {
			add += n - cur;
			cur = n;
		}
	}

	printf("%d\n", add);
	return 0;
}
