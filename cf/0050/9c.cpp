#include <bits/stdc++.h>
using namespace std;

int process(char *n, int cur, int len) {
	if (cur == len-1) { return (n[cur] >= '1') ? 1 : 0; }
	if (n[cur] > '1') {
		return (1 << (len-cur)) - 1;
	} else if (n[cur] == '1') {
		int v = process(n, cur+1, len);
		return v + (1<<(len-cur-1));
	} else {
		return process(n, cur+1, len);
	}
}

int main() {
	char n[16]; scanf("%s", n);
	int len = strlen(n), ans = 0;
	if (len <= 1) {
		ans = 1;
	} else {
		ans = process(n, 0, len);
	}

	printf("%d\n", ans);
	return 0;
}
