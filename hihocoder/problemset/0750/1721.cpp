#include <bits/stdc++.h>
using namespace std;

#define MAXN 500000
char str[MAXN+1];

int check(int l, int r, int cnt) {
	if (l > r) { return -1; }
	if (str[l] != str[r]) {
		if (cnt > 0) {
			return l;
		} else {
			if (check(l+1, r, cnt+1) == -1) {
				return l;
			} else {
				return r;
			}
		}
	}

	return check(l+1, r-1, cnt);
}

int main() {
	scanf("%s", str);
	int len = strlen(str);
	int pos = check(0, len-1, 0);
	if (pos == -1) { pos = (len-1) >> 1; }
	while (pos > 0 && str[pos] == str[pos-1]) { --pos; }
	printf("%d\n", pos+1);
	return 0;
}
