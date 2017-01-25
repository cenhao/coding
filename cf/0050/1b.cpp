#include <cstdio>
using namespace std;

int main() {
	int n; scanf("%d", &n);

	char input[64]; 
	for (int i=0; i<n; ++i) {
		scanf("%s", input);
		int r, c;
		if (input[0] == 'R' && input[1] >= '0' && input[1] <= '9'
			&& sscanf(input, "R%dC%d", &r, &c) == 2) {
			int len = 0, tmp = c;
			while (tmp > 0) {
				int remainder = tmp % 26;
				if (!remainder) { remainder += 26; }
				tmp = (tmp - remainder) / 26;
				input[len++] = remainder + 'A' - 1;
			}

			for (int j=len-1; j>=0; --j) { printf("%c", input[j]); }
			printf("%d\n", r);
		} else {
			int pos = 0;
			c = 0;
			while (input[pos] > '9' || input[pos] < '0') {
				c = c*26 + input[pos++] - 'A' + 1;
			}
			sscanf(&input[pos], "%d", &r);
			printf("R%dC%d\n", r, c);
		}
	}

	return 0;
}
