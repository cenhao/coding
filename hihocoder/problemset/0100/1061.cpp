#include <stdio.h>
#define MB (1 << 20)
#define INF 0x7fffff00

char buff[10 * MB + 5];

char s[3];
int slen[3];

int main() {
	int t;
	for (scanf("%d", &t); t>0; --t) {
		int n; scanf("%d", &n);
		if (n == 0) {
			printf("NO\n");
			continue;
		}
		scanf("%s", buff);
		int cur = 2;
		char last = 0;
		s[0] = s[1] = s[2] = 0;
		slen[0] = slen[1] = slen[2] = INF;
		bool ok = false;

		for (int i=0; i<=n; ++i) {
			if (buff[i] != last) {
				int pre = (cur+2) % 3;
				int ppre = (cur+1) % 3;
				if (s[cur] == s[pre]+1 && s[cur] == s[ppre]+2 &&
						slen[cur] >= slen[pre] && slen[ppre] >= slen[pre]) {
					ok = true;
					break;
				}

				cur = ppre;
				last = s[cur] = buff[i];
				slen[cur] = 0;
			}

			++slen[cur];
		}
		printf("%s\n", ok ? "YES" : "NO");
	}

	return 0;
}
