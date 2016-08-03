/*
ID: cenhao11
PROG: msquare
LANG: C++11
*/

#include <stdio.h>
#include <string.h>
#include <queue>
using namespace std;

#define HASH 104729

struct Square {
	char move;
	unsigned short cnt;
	int cur;
	int prev;
} squares[HASH];

int target;

typedef int getNextState(int);

int A(int state) {
	int v[8];
	for (int i=0; i<8; ++i) {
		v[i] = state % 10;
		state /= 10;
	}

	for (int i=0; i<4; ++i) {
		int tmp = v[i];
		v[i] = v[7-i];
		v[7-i] = tmp;
	}

	int ret = 0;
	for (int i=7; i>=0; --i) {
		ret = ret * 10 + v[i];
	}

	return ret;
}

int B(int state) {
	int v[8];
	for (int i=0; i<8; ++i) {
		v[i] = state % 10;
		state /= 10;
	}

	int tmp = v[3];
	for (int i=3; i>=1; --i) { v[i] = v[i-1]; }
	v[0] = tmp;
	tmp = v[4];
	for (int i=4; i<=6; ++i) { v[i] = v[i+1]; }
	v[7] = tmp;

	int ret = 0;
	for (int i=7; i>=0; --i) {
		ret = ret * 10 + v[i];
	}

	return ret;
}

int C(int state) {
	int v[8];
	for (int i=0; i<8; ++i) {
		v[i] = state % 10;
		state /= 10;
	}

	int tmp = v[1];
	v[1] = v[6]; v[6] = v[5];
	v[5] = v[2]; v[2] = tmp;

	int ret = 0;
	for (int i=7; i>=0; --i) {
		ret = ret * 10 + v[i];
	}

	return ret;
}

getNextState* funcs[3] = { A, B, C };

int getEmptySquare(int state) {
	int idx = state % HASH;
	while (squares[idx].move != 0) {
		++idx;
		if (idx >= HASH) { idx = 0; }
	}
	return idx;
}

int getSquare(int state) {
	int idx = state % HASH;
	while (squares[idx].cur != state && squares[idx].move != 0) {
		++idx;
		if (idx >= HASH) { idx = 0; }
	}
	return (squares[idx].move == 0) ? -1 : idx;;
}

int printPath(int curIdx) {
	if (squares[curIdx].prev == -1) {
		return 0;
	}
	int cnt = printPath(squares[curIdx].prev);
	if (cnt == 60) {
		cnt = 0;
		printf("\n");
	}

	printf("%c", squares[curIdx].move);
	return cnt + 1;
}

void bfs() {
	int start = 87654321;
	if (start == target) {
		printf("0\n\n");
		return;
	}
	memset(squares, 0, sizeof(squares));
	queue<int> q;
	int idx = getEmptySquare(start);
	squares[idx].cnt = 0;
	squares[idx].cur = start;
	squares[idx].prev = -1;
	squares[idx].move = 'X';
	q.push(idx);

	while (!q.empty()) {
		int curIdx = q.front();
		q.pop();
		int v = squares[curIdx].cur;

		for (int i=0; i<3; ++i) {
			int nxt = funcs[i](v);

			if (nxt == target) {
				printf("%d\n", squares[curIdx].cnt + 1);
				int pcnt = printPath(curIdx);
				if (pcnt == 60) {
					pcnt = 0;
					printf("\n");
				}
				printf("%c\n", 'A' + i);
				return;
			}

			if (-1 != getSquare(nxt)) { continue; }

			int nxtIdx = getEmptySquare(nxt);
			squares[nxtIdx].cur = nxt;
			squares[nxtIdx].prev = curIdx;
			squares[nxtIdx].cnt = squares[curIdx].cnt + 1;
			squares[nxtIdx].move = 'A' + i;
			q.push(nxtIdx);
		}
	}
}

int main() {
	freopen("msquare.in", "r", stdin);
	freopen("msquare.out", "w", stdout);

	int tmp;
	int base = 1;
	target = 0;
	for (int i=0; i<8; ++i) {
		scanf("%d", &tmp);
		target += tmp * base;
		base *= 10;
	}

	bfs();
}
