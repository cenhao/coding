#include <bits/stdc++.h>
using namespace std;

int main() {
	char in[200]; scanf("%s", in);

	int base = 0, cur = 0, len = strlen(in);
	while (base < 100 && cur < len) {
		base = base * 10 + in[cur] - '0';
		int cnt = 0, nxt = cur+1;
		int i, miss;
		for (i=base+1; i<=100 && nxt<len; ++i) {
			char tmp[4]; snprintf(tmp, sizeof(tmp), "%d", i);
			int tlen = (i < 10) ? 1 : ((i < 100) ? 2 : 3);
			bool fit = true;
			for (int j=0; j<tlen; ++j) {
				if (in[nxt+j] != tmp[j]) {
					fit = false;
					break;
				}
			}

			if (!fit) {
				++cnt;
				if (cnt > 1) { break; }
				miss = i;
			} else {
				nxt += tlen;
			}
		}

		if (cnt < 2) {
			printf("%d\n", (cnt == 1) ? miss : i);
			break;
		}
		++cur;
	}

	return 0;
}
