#include <stdio.h>
#include <string.h>

#define MAXC 400000

char combinations[MAXC][10];
int first;

int require[9][9];
bool connect[9][9];
bool vis[9];

int n;
int _;

inline void set(int a, int b, int r) {
	require[a][b] = r;
	require[b][a] = r;
}

int find(int start, int depth, char *buf) {
	vis[start] = true;
	buf[depth] = '1' + start;
	int cnt = 0;
	if (depth >= 3) {
		for (int i=0; i<=depth; ++i) {
			combinations[first][i] = buf[i];
		}
		++cnt;
		combinations[first++][depth+1] = 0;
	}

	for (int i=0; i<9; ++i) {
		if (!vis[i] &&
				(require[start][i] < 0 || vis[require[start][i]])) {
			cnt += find(i, depth+1, buf);
		}
	}
	vis[start] = false;

	return cnt;
}

int find() {
	memset(vis, 0, sizeof(vis));
	char buf[10];
	int cnt = 0;
	for (int i=0; i<9; ++i) {
		cnt += find(i, 0, buf);
	}

	return cnt;
}

void prep() {
	memset(require, -1, sizeof(require));
	set(0, 2, 1); set(0, 6, 3); set(0, 8, 4);
	set(1, 7, 4);
	set(2, 6, 4); set(2, 8, 5);
	set(3, 5, 4);
	set(6, 8, 7);
	find();
}

int process() {
	int cnt = 0;
	for (int i=0; i<first; ++i) {
		int match = 0;
		for (int i2=strlen(combinations[i])-1; i2>=1; --i2) {
			if (connect[combinations[i][i2]-'1'][combinations[i][i2-1]-'1']) {
				++match;
			}
		}

		if (match == n) { ++cnt; }
	}

	return cnt;
}

int main() {
	prep();
	for (scanf("%d", &_); _>0; --_) {
		scanf("%d", &n);
		memset(connect, 0, sizeof(connect));
		for (int i=0; i<n; ++i) {
			int a, b; scanf("%d %d", &a, &b);
			--a; --b;
			connect[a][b] = connect[b][a] = true;
		}
		printf("%d\n", process());
	}
	return 0;
}
