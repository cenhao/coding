#include <bits/stdc++.h>
using namespace std;

#define MAXS 10000
char msg[MAXS+5];

bool possible(int chunk, int k, int len) {
	int cnt = 1;
	char buff[32];
	int elen = 0, clen = 0;
	sprintf(buff, "(1/%d)", chunk);
	elen = strlen(buff);
	for (int i=0; i<len && cnt<=chunk; ++i) {
		int cur = i+1;
		if (msg[i] != ' ') {
			while (cur<len && msg[cur]!=' ') { ++cur; }
		}

		int wlen = cur-i;
		if (clen+elen+wlen > k) {
			++cnt;
			sprintf(buff, "(%d/%d)", cnt, chunk);
			elen = strlen(buff);
			clen = 0;
			if (clen+elen+wlen > k) { return true; } // too many chunks
		}

		clen += wlen;
		i = cur-1;
	}

	return cnt <= chunk;
}

void print(int chunk, int k, int len) {
	char buff[32];
	int cnt = 1, elen, clen = 0, last = 0;
	sprintf(buff, "(1/%d)", chunk);
	elen = strlen(buff);
	for (int i=0; i<len; ++i) {
		int cur = i+1;
		if (msg[i] != ' ') { while (cur<len && msg[cur]!=' ') { ++cur; } }
		int wlen = cur - i;
		if (clen + elen + wlen > k) {
			for (int j=last; j<cur-wlen; ++j) { printf("%c", msg[j]); }
			printf("%s\n", buff);
			last = cur-wlen;
			++cnt;
			sprintf(buff, "(%d/%d)", cnt, chunk);
			elen = strlen(buff);
			clen = 0;
		}

		i = cur - 1;
		clen += wlen;
	}

	if (last < len) {
		for (int i=last; i<len; ++i) { printf("%c", msg[i]); }
		printf("%s\n", buff);
	}
}

int main() {
	fgets(msg, sizeof(msg), stdin);
	int k; sscanf(msg, "%d", &k);

	fgets(msg, sizeof(msg), stdin);
	int len = strlen(msg);
	if (msg[len-1] == '\n') { msg[--len] = 0; }

	int l = len / k + (len % k == 0 ? 0 : 1);
	int r = len;

	while (l <= r) {
		int m = (l + r) >> 1;
		if (possible(m, k, len)) {
			r = m - 1;
		} else {
			l = m + 1;
		}
	}

	print(l, k, len);
	return 0;
}
