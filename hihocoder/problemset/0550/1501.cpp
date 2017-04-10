#include <bits/stdc++.h>
using namespace std;

#define MAXN 100

char var_name[MAXN+1];
char output[2*MAXN+1];

int main() {
	int n; scanf("%d", &n);
	while (n--) {
		scanf("%s", var_name);
		int len = strlen(var_name);
		int cur = 0;
		bool to_upper = false;
		for (int i=0; i<len; ++i) {
			if (var_name[i] == '_') {
				to_upper = true;
			} else if (var_name[i] >= 'A' && var_name[i] <= 'Z') {
				output[cur++] = '_';
				output[cur++] = tolower(var_name[i]);
			} else {
				output[cur++] = (to_upper) ? toupper(var_name[i]) : var_name[i];
				to_upper = false;
			}
		}

		output[cur] = 0;
		printf("%s\n", output);
	}

	return 0;
}
