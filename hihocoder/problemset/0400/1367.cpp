#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

#define MAXL 100
#define MAXSUM 450
#define MOD 1000000007

char s[MAXL+1];
char *target;
int ql[MAXL];
int dp[2][MAXSUM];

int main() {
	scanf("%s", s);
	char *ptr = NULL;
	char *left = strtok_r(s, "=", &ptr);
	target = strtok_r(NULL, "=", &ptr);
	reverse(target, target+strlen(target));
	int cnt = 0;

	for (ptr=NULL; ; ++cnt, left=NULL) {
		char *tmp = strtok_r(left, "+", &ptr);
		if (tmp == NULL) { break; }
		ql[cnt] = strlen(tmp);
	}

	memset(dp, 0, sizeof(dp));
	dp[0][0] = 1;
	int cur = 0, pre = 1;
	int mx = 0;
	for (int i=0, end=strlen(target), last=0; i<end; ++i, last=target[i-1]-'0') {
		pre = cur; cur = (cur + 1) & 1;
		memset(dp[cur], 0, sizeof(dp[cur]));
		for (int i1=last; i1<=mx; i1+=10) { dp[cur][i1/10] = dp[pre][i1]; }
		mx = mx / 10 - (((mx % 10) >= last) ? 0 : 1);

		for (int i1=0; i1<cnt; ++i1) {
			if (ql[i1] <= i) { continue; }
			pre = cur; cur = (cur + 1) & 1;
			memset(dp[cur], 0, sizeof(dp[cur]));

			for (int i2=(i+1==ql[i1])?1:0; i2<10; ++i2) {
				for (int i3=0; i3<=mx; ++i3) {
					dp[cur][i3+i2] = (dp[cur][i3+i2]+dp[pre][i3]) % MOD;
				}
			}

			mx += 9;
		}
	}

	int need = target[strlen(target)-1] - '0';
	printf("%d\n", dp[cur][need]);

	return 0;
}
