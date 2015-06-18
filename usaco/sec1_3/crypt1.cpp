/*
ID: cenhao11
PROG: crypt1
LANG: C++11
*/

#include <stdio.h>
#include <string.h>

int digit[10];
int mark[10];

bool check(int num, int limit)
{
	char buff[10] = {0, };
	snprintf(buff, 10, "%d", num);

	int len = strlen(buff);
	if (len > limit) { return false; }
	for (int i=0; i<len; ++i) {
		if (mark[buff[i]-'0'] == 0) { return false; }
	}

	return true;
}

int dfs2(int pos, int end, int first, int sum)
{
	int prod = 0;
	if (pos == 2) {
		prod = first * sum;
		return check(prod, 4) ? 1 : 0;
	}

	int res = 0;

	for (int i=0; i<end; ++i) {
		prod = first * digit[i];
		res += check(prod, 3) ? dfs2(pos+1, end, first, sum*10+digit[i]) : 0;
	}

	return res;
}

int dfs(int pos, int end, int sum)
{
	if (pos == 3) {
		return dfs2(0, end, sum, 0);
	}

	sum *= 10;
	int res = 0;
	for (int i=0; i<end; ++i) {
		int tmp = sum + digit[i];
		res += dfs(pos+1, end, tmp);
	}

	return res;
}

int main()
{
	freopen("crypt1.in", "r", stdin);
	freopen("crypt1.out", "w", stdout);

	int n;
	while (EOF != scanf("%d", &n)) {
		memset(mark, 0, sizeof(mark));
		for (int i=0; i<n; ++i) {
			scanf("%d", &digit[i]);
			mark[digit[i]] = 1;
		}

		printf("%d\n", dfs(0, n, 0));
	}

	return 0;
}
