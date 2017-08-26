#include <bits/stdc++.h>
using namespace std;

#define MAXN 1000

char buff[MAXN+1];
bool exist[26];

int main() {
	int k; scanf("%s %d", buff, &k);
	int len = strlen(buff);
	if (k > len) {
		printf("impossible\n");
		return 0;
	}

	memset(exist, false, sizeof(exist));
	int cnt = 0;
	for (int i=0; i<len; ++i) {
		int j = buff[i] - 'a';
		if (!exist[j]) { ++cnt; }
		exist[j] = true;
	}

	printf("%d\n", max(0, k - cnt));
	return 0;
}
