#include <bits/stdc++.h>
using namespace std;

const int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

// The step by just walking from the center without same-color-teleporting
//                    a  b  c  d  e  f  g  h  i  j  k  l  m  n  o  p  q  r  s  t  u  v  w  x  y  z
const int step[26] = {0, 1, 2, 1, 2, 1, 2, 1, 2, 3, 2, 3, 4, 3, 2, 3, 4, 3, 2, 3, 4, 3, 2, 3, 4, 5};

char get_value(int x, int y) {
	int mx = max(abs(x), abs(y));
	if (mx == 0) { return 'A'; }

	int a = (mx-1) * 2 + 1, b;

	if (y == mx && x != -mx) {
		b = x + mx;
	} else if (x == mx && y != mx) {
		b = mx * 2 + mx - y;
	} else if (y == -mx && x != mx) {
		b = mx * 2 * 2 + mx - x;
	} else {
		b = mx * 2 * 3 + y + mx;
	}

	int v = ((a % 26) * (a % 26) + b) % 26;
	v = (v + 25) % 26;
	return 'A' + v;
}

int min_move(int x, int y, bool rec = true) {
	char c = get_value(x, y);
	// 1, first walk to the closing character, then teleport (+1)
	int ans = step[c-'A'] + 1;
	
	// 2, by just walking
	ans = min(ans, abs(x) + abs(y));

	// 3, see if it's faster to walk from adjacent cell
	for (int i=0; i<4; ++i) {
		int xx = x + dir[i][0], yy = y + dir[i][1];
		if (rec) {
			// from #4 below, the max step requires will be 4
			// so if without recursive, the maxium could be 4
			// then if there's an 'A' two steps away, we can leverage
			// that to cut the cost to 3
			// but this will only help the first time, as for the 
			// second step, it will need to be 2 to help optimize,
			// then only the center 'A' can be used.
			// But in that case other logic has already covered it
			ans = min(ans, min_move(xx, yy, false)+1);
		} else {
			char v = get_value(xx, yy);
			ans = min(ans, step[v-'A']+2);
		}
	}

	// 4
	// From the commented code below, it can be proved that
	// for each character, it's either next to 'A', which requires
	// at most 3 step (center -> teleport to A -> walk)
	// or is next to 'BDFH', those are characters next to the center,
	// then it can be reached in at most 4 steps
	// (center -> walk to BDFH > teleport -> walk)
	// and interestingly, a charactor can either be reach by 'A' or
	// 'BDFH', but not both.
	// and even chars can be reached only by 'BDFH', odd can be reached only
	// by 'A' on the other hand
	ans = min(ans, ((c-'A')&1) ? 3 : 4);

	return ans;
}

int main() {
	int n; scanf("%d", &n);
	while (n--) {
		int x, y; scanf("%d %d", &x, &y);
		printf("%d\n", min_move(x, y));
	}

	return 0;
}
/*
#define MAXN 2501
#define OFF ((MAXN-1)/2)

const int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
char mat[MAXN][MAXN];

int main() {
	mat[OFF][OFF] = 'A';
	char cur = 'B';

	for (int i=1; i<=OFF; ++i) {
		for (int j=0; j<i*2; ++j) {
			mat[OFF-i][OFF-i+1+j] = cur;
			cur = (cur-'A'+1) % 26 + 'A';
		}

		for (int j=0; j<i*2; ++j) {
			mat[OFF-i+1+j][OFF+i] = cur;
			cur = (cur-'A'+1) % 26 + 'A';
		}

		for (int j=0; j<i*2; ++j) {
			mat[OFF+i][OFF+i-1-j] = cur;
			cur = (cur-'A'+1) % 26 + 'A';
		}

		for (int j=0; j<i*2; ++j) {
			if (OFF+i-1-j < 0) { break; }
			mat[OFF+i-1-j][OFF-i] = cur;
			cur = (cur-'A'+1) % 26 + 'A';
		}
	}

	bool ok[26];
	memset(ok, false, sizeof(ok));
	for (int i=0; i<MAXN; ++i) {
		for (int j=0; j<MAXN; ++j) {
			for (int k=0; k<4; ++k) {
				int x = i + dir[k][0], y = j + dir[k][1];
				if (x < 0 || y < 0 || x >= MAXN || y >= MAXN) { continue; }
				if (mat[x][y] == 'A' ||
					mat[x][y] == 'B' ||
					mat[x][y] == 'F' ||
					mat[x][y] == 'H' ||
					mat[x][y] == 'D') { ok[mat[i][j]-'A'] = true; }
				//if (mat[x][y] == 'A') { ok[mat[i][j]-'A'] = true; }
			}
		}
	}

	for (int i=0; i<26; ++i) {
		printf("%c %d\n", i+'A', ok[i] ? 1 : 0);
	}

	return 0;
}
*/
