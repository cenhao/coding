#include <bits/stdc++.h>
using namespace std;

#define MAXN 100000

char src[MAXN+10], tar[MAXN+10];

int main() {
	fgets(src, sizeof(src), stdin);
	fgets(tar, sizeof(tar), stdin);

	int slen = strlen(src), tlen = strlen(tar);
	if (src[slen-1] == '\n') { src[--slen] = 0; }
	if (tar[tlen-1] == '\n') { src[--tlen] = 0; }

	int cnt = 0, pos=0;
	bool possible = slen == tlen;
	for (int i=0; possible && i<slen; ++i) {
		if (src[i] == '_') { continue; }
		while (pos < tlen && tar[pos] == '_') { ++pos; }
		if (pos >= tlen || src[i] != tar[pos] ||
			(src[i] == 'R' && i > pos) ||
			(src[i] == 'L' && i < pos)) {
			possible = false;
		}

		cnt += abs(i-pos);
		++pos;
	}

	while (pos < tlen && possible) {
		if (tar[pos] != '_') { possible = false; }
		++pos;
	}

	printf("%d\n", possible ? cnt : -1);
	return 0;
}
