#include <bits/stdc++.h>
using namespace std;

#define MAXN 1000

char line[MAXN+1];

int main() {
	int n; scanf("%d", &n); 
	int x, y;
	for (int i=0; i<n; ++i) {
		scanf("%s", line);
		for (int j=0; j<n; ++j) {
			if (line[j] == 'X') { x = i; y = j; }
		}
	}

	printf("%d,%d\n", x, y);
	return 0;
}
