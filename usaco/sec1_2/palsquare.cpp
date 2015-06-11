/*
ID: cenhao11
PROG: palsquare
LANG: C++
*/

#include <stdio.h>

inline char ToChar(int num)
{
	if (num < 10) { return num + '0'; }
	return 'A' + num - 10;
}

bool ReverseAndCheck(char *szStr/* in and out */, int len)
{
	bool pal = true;

	for (int i=len/2-1; i>=0; --i) {
		char tmp = szStr[i];
		szStr[i] = szStr[len-i-1];
		szStr[len-i-1] = tmp;

		pal &= (szStr[i] == szStr[len-i-1]);
	}

	return pal;
}

int GetAndCheckStrInBase(int num, int base, char *szStr)
{
	int len = 0;

	while (num > 0) { // Don't care the 0 scenario
		szStr[len] = ToChar(num % base);
		num /= base;
		++len;
	}

	szStr[len] = 0;
	return (int)ReverseAndCheck(szStr, len);
}

int main()
{
	freopen("palsquare.in", "r", stdin);
	freopen("palsquare.out", "w", stdout);

	int b;
	while (EOF != scanf("%d", &b)) {
		char szN[50] = {0, };
		char szN2[50] = {0, };

		for (int i=1; i<=300; ++i) {
			if (GetAndCheckStrInBase(i*i, b, szN2)) {
				GetAndCheckStrInBase(i, b, szN);
				printf("%s %s\n", szN, szN2);
			}
		}
	}

	return 0;
}
