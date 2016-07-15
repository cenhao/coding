/*
ID: cenhao11
PROG: preface
LANG: C++11
*/

#include <stdio.h>
#include <string.h>

const int Count[3][10] = {
	{0, 1, 3, 6, 7, 7, 8, 10, 13, 14},
	{0, 0, 0, 0, 1, 2, 3,  4,  5,  5},
	{0, 0, 0, 0, 0, 0, 0,  0,  0,  1}
};

const char Letter[7] = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};

int cnt[7 + 3]; // adding 3 for easier coding

int main() {
	freopen("preface.in", "r", stdin);
	freopen("preface.out", "w", stdout);

	int n;
	scanf("%d", &n);

	int base = 1;
	int left = 0;
	for (int i=0; i<7 && n > 0; i+=2) {
		int muliplier = n / 10;
		int remainder = n % 10;

		for (int j=0; j<3; ++j) {
			cnt[i+j] += Count[j][9] * muliplier * base;
			if (remainder) {
				cnt[i+j] += Count[j][remainder - 1] * base;
				cnt[i+j] += (Count[j][remainder] - Count[j][remainder-1]) * (left + 1);
			}
		}

		n /= 10;
		left += remainder * base;
		base *= 10;
	}

	for (int i=0; i<7 && cnt[i] > 0; ++i) {
		printf("%c %d\n", Letter[i], cnt[i]);
	}

	return 0;
}
