/* Hiho coder 1039. At the beginning I was thinking about shrinking the
 * string first, and then find longest palindrome, however, this won't
 * work for strings like this: ABABBA.
 * The algorithm is to simply enumberate all the possibilities and shrink
 * the string to find the maximum.
 */

#include <algorithm>
using namespace std;

#include <stdio.h>
#include <string.h>

#define MAXS 100

char str[MAXS+3];
char mstr[MAXS+3];
char ts[2][MAXS+3];
int first[MAXS+3];

int shrink(char *s) {
	int len = strlen(s);
	memcpy(ts[0], s, len*sizeof(char));
	ts[0][len] = '$';
	ts[0][++len] = 0;

	int cur = 1, pre = 0;
	int pos, scnt, cnt = 0;
	do {
		pos = -1; scnt = 0;
		for (int i=0; i<len; ++i) {
			if (pos < 0 || ts[pre][i] != ts[cur][pos]) {
				if (i - first[pos] > 1) {
					scnt += i - first[pos];
					--pos;
				}
				ts[cur][++pos] = ts[pre][i];
				first[pos] = i;
			}
		}

		len = pos + 1;
		cnt += scnt;
		memcpy(ts[pre], ts[cur], len*sizeof(char));
		ts[pre][len] = 0;
		cur = (cur + 1) % 2;
		pre = (pre + 1) % 2;
	} while (scnt > 0);

	return cnt;
}

int process() {
	int mx = 0;
	for (int i=0, len=strlen(str); i<len; ++i) {
		for (int i2=0; i2<i; ++i2) {
			mstr[i2] = str[i2];
		}
		for (int i2=i; i2<len; ++i2) {
			mstr[i2+1] = str[i2];
		}
		mstr[len+1] = 0;

		for (int i2=0; i2<3; ++i2) {
			mstr[i] = 'A' + i2;
			mx = max(mx, shrink(mstr));
		}
	}

	return mx;
}

int main() {
	int t;
	scanf("%d", &t);

	for (int i=0; i<t; ++i) {
		scanf("%s", str);
		printf("%d\n", process());
	}

	return 0;
}
