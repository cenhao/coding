/*
#include <stdio.h>
#include <string.h>

#define MAXS 1000

char str[MAXS+1];

int main() {
	while (EOF != scanf("%s", str)) {
		int len = strlen(str);
		for (int i=len-1; i>=0; --i) {
			if (str[i] <= 'Z') {
				str[len] = str[i];
				int i2;
				for (i2=i+1; i2<len && str[i2]>='a'; ++i2) {
					str[i2-1] = str[i2];
				}
				str[i2-1] = str[len];
			}
		}

		str[len] = 0;
		printf("%s\n", str);
	}
}
*/

// The correct solution
#include <stdio.h>

#define MAXS 1000

char str[MAXS+1];

int main() {
	while (EOF != scanf("%s", str)) {
		for (int i=0; str[i]!=0; ++i) {
			if (str[i] >= 'a') { printf("%c", str[i]); }
		}
		for (int i=0; str[i]!=0; ++i) {
			if (str[i] <= 'Z') { printf("%c", str[i]); }
		}
		printf("\n");
	}

	return 0;
}
