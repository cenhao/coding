#include <bits/stdc++.h>
using namespace std;

int main() {
	char a[12], b[12]; scanf("%s %s", a, b);
	int len1 = strlen(a), len2 = strlen(b);
	sort(a, a+len1);
	if (a[0] == '0') {
		for (int i=1; i<len1; ++i) {
			if (a[i] != '0') {
				swap(a[i], a[0]);
				break;
			}
		}
	}

	printf("%s", strcmp(a, b) == 0 ? "OK\n" : "WRONG_ANSWER\n");
	return 0;
}
