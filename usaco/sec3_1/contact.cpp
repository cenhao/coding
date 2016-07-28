/*
ID: cenhao11
PROG: contact
LANG: C++11
*/

#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

#define MAXS 200000
#define MAXB 12
#define FREQ_SIZE ((1 << MAXB) * 2)

const int Mask[13] = {
	0,
	0x001, 0x003, 0x007, 0x00f,
	0x01f, 0x03f, 0x07f, 0x0ff,
	0x1ff, 0x3ff, 0x7ff, 0xfff
};

struct Frequency {
	int pattern;
	int len;
	int cnt;
} freq[FREQ_SIZE];

bool cmpFreq(Frequency f1, Frequency f2) {
	if (f1.cnt == f2.cnt) {
		if (f1.len == f2.len) {
			return f1.pattern < f2.pattern;
		}

		return f1.len < f2.len;
	}

	return f1.cnt > f2.cnt;
}

int main() {
	freopen("contact.in", "r", stdin);
	freopen("contact.out", "w", stdout);

	memset(freq, 0, sizeof(freq));
	int a, b, n;
	char signal[MAXS+1];
	scanf("%d %d %d", &a, &b, &n);

	int eos = 0; // end of string
	while (EOF != scanf("%s", &signal[eos])) {
		eos += strlen(&signal[eos]);
	}

	int buff = 0;
	for (int i=0; i<eos; ++i) {
		int bit = (signal[i] == '0') ? 0 : 1;
		buff = (buff << 1) | bit;

		for (int j=a; j<=b && i+1>=j; ++j) {
			int pattern = buff & Mask[j];
			int idx = (Mask[j-1] << 1) + pattern;
			freq[idx].pattern = pattern;
			freq[idx].len = j;
			++freq[idx].cnt;
		}
	}

	int freqCnt = Mask[b] << 1;
	sort(freq, freq+freqCnt, cmpFreq);
	int lastFreq = -1;
	int showCnt = 0;
	int idx = 0;
	int lineCnt;

	while (freq[idx].cnt >= 1) {
		if (freq[idx].cnt != lastFreq) {
			++ showCnt;
			if (showCnt > n) { break; }
			if (lastFreq > 0) { printf("\n"); }
			lastFreq = freq[idx].cnt;
			printf("%d", lastFreq);
			lineCnt = 0;
		}

		printf("%c", (lineCnt % 6 == 0) ? '\n' : ' ');
		++lineCnt;
		int mask = 1;
		mask <<= freq[idx].len - 1;
		for (int mask=1<<(freq[idx].len-1); mask>0; mask>>=1) {
			printf("%c", (freq[idx].pattern & mask) ? '1' : '0');
		}

		++idx;
	}

	printf("\n");
	return 0;
}
