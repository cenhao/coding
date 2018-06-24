#include <bits/stdc++.h>
using namespace std;

#define MAXN 100
char b[2][MAXN+1];
bool ok[MAXN][4];
int cnt[MAXN][4];

int main() {
	scanf("%s", b[0]);
	scanf("%s", b[1]);
	int len = strlen(b[0]);
	memset(cnt, 0, sizeof(cnt));

	for (int i=1; i<len; ++i) {
		cnt[i][0] = max(cnt[i-1][0], max(cnt[i-1][1], max(cnt[i-1][2], cnt[i-1][3])));
		int state = (b[0][i]=='X'?1:0) | (b[1][i]=='X'?2:0);
		int pstate = (b[0][i-1]=='X'?1:0) | (b[1][i-1]=='X'?2:0);
		if (state == 0) {
			if ((pstate & 1) == 0) {
				cnt[i][3] = max(cnt[i][3], max(cnt[i-1][0], cnt[i-1][2])+1);
			}
			if ((pstate & 2) == 0) {
				cnt[i][3] = max(cnt[i][3], max(cnt[i-1][0], cnt[i-1][1])+1);
			}
		}
		if ((state&1)==0 && pstate==0) {
			cnt[i][1] = max(cnt[i][1], cnt[i-1][0]+1);
		}
		if ((state&2)==0 && pstate==0) {
			cnt[i][2] = max(cnt[i][2], cnt[i-1][0]+1);
		}
	}

	int ans = 0;
	for (int i=0; i<4; ++i) { ans = max(ans, cnt[len-1][i]); }
	printf("%d\n", ans);
	return 0;
}
