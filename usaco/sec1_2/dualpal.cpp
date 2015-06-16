/*
ID: cenhao11
PROG: dualpal
LANG: C++11
*/

#if 0
//This is the code for generating the array
#include <stdio.h>

bool IsDualPalindromeInBase(int num, int base)
{
	static char strBuff[32] = {0, };
	int len = 0;

	while (num > 0) {
		strBuff[len++] = num % base;
		num /= base;
	}

	for (int i=len/2-1; i>=0; --i) {
		if (strBuff[i] != strBuff[len-i-1]) { return false; }
	}

	return true;
}

bool CheckDualPalindromes(int num)
{
	int cnt = 0; /* counter for num being a dual palindrome in base X */
	for (int i=2; i<=10; ++i) {
		if (IsDualPalindromeInBase(num, i)) {
			++cnt;

			if (cnt > 2) { break; }
		}
	}

	return (cnt >= 2);
}

int main()
{
	int cnt = 0; /* counter for dual palindromes that are larger than 10000 */
	for (int i=1; cnt < 15; ++i) {
		if (CheckDualPalindromes(i)) {
			if (i > 10000) { ++cnt; }
			printf("%s%d", (i == 1) ? "{" : " ,", i);
		}
	}

	printf("}\n");
	return 0;
}

#endif

#include <stdio.h>

const int dual[] = {1 ,2 ,3 ,4 ,5 ,6 ,7 ,8 ,9 ,10 ,15 ,16 ,17 ,18 ,20 ,21 ,24 ,26 ,27 ,28 ,31 ,33 ,36 ,40 ,45 ,46 ,50 ,51 ,52 ,55 ,57 ,63 ,65 ,67 ,73 ,78 ,80 ,82 ,85 ,88 ,91 ,92 ,93 ,98 ,99 ,100 ,104 ,105 ,107 ,109 ,111 ,114 ,119 ,121 ,127 ,129 ,130 ,135 ,141 ,142 ,150 ,151 ,154 ,160 ,164 ,170 ,171 ,173 ,178 ,182 ,185 ,186 ,191 ,195 ,200 ,203 ,209 ,212 ,215 ,219 ,227 ,235 ,242 ,246 ,252 ,255 ,257 ,264 ,273 ,282 ,292 ,300 ,313 ,316 ,325 ,328 ,333 ,341 ,342 ,343 ,357 ,364 ,365 ,373 ,381 ,393 ,400 ,414 ,427 ,434 ,438 ,446 ,455 ,464 ,471 ,484 ,495 ,511 ,513 ,546 ,555 ,560 ,564 ,585 ,624 ,626 ,644 ,646 ,651 ,656 ,666 ,676 ,692 ,693 ,701 ,717 ,728 ,730 ,757 ,771 ,777 ,787 ,819 ,820 ,856 ,868 ,910 ,939 ,975 ,1023 ,1025 ,1066 ,1105 ,1221 ,1285 ,1312 ,1365 ,1432 ,1441 ,1460 ,1539 ,1550 ,1640 ,1667 ,1755 ,1885 ,2000 ,2188 ,2268 ,2293 ,2550 ,2565 ,2709 ,2730 ,2910 ,2920 ,2925 ,2997 ,3069 ,3074 ,3075 ,3280 ,3315 ,3550 ,3591 ,3640 ,3663 ,3735 ,3740 ,3855 ,3951 ,3999 ,4095 ,4097 ,4161 ,4225 ,4257 ,4289 ,4369 ,4433 ,4593 ,4617 ,4681 ,5001 ,5049 ,5125 ,5189 ,5397 ,5461 ,5740 ,5840 ,5854 ,6148 ,6200 ,6560 ,6562 ,6643 ,6697 ,6724 ,6761 ,6825 ,6886 ,6889 ,6953 ,7300 ,7373 ,7381 ,7409 ,7447 ,7462 ,7517 ,7667 ,7703 ,7777 ,7801 ,7997 ,8038 ,8119 ,8194 ,8200 ,8258 ,8281 ,8322 ,8386 ,8578 ,8778 ,8802 ,9009 ,9103 ,9201 ,9222 ,9490 ,9958 ,10252 ,10308 ,10658 ,10794 ,10858 ,10922 ,10986 ,11253 ,11314 ,11757 ,11898 ,11950 ,12291 ,12355 ,12419};

int find(int x)
{
	int l = 0, r = sizeof(dual) / sizeof(int) - 1;

	while (l <= r) {
		int m = (l + r) >> 1;
		if (dual[m] > x) { r = m - 1; }
		else { l = m + 1; }
	}

	return l;
}

int main()
{
	freopen("dualpal.in", "r", stdin);
	freopen("dualpal.out", "w", stdout);

	int n, s;
	while (EOF != scanf("%d %d", &n, &s))
	{
		int idx = find(s);
		for (int i=0; i<n; ++i) { printf("%d\n", dual[idx + i]); }
	}

	return 0;
}
