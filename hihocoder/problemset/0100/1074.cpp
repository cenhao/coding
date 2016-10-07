#include <algorithm>
using namespace std;

#include <stdio.h>
#include <string.h>

#define MAXN 100000
#define LOG2NF 16

int rmxq[MAXN][LOG2NF+1]; // range maximum query
int rmnq[MAXN][LOG2NF+1]; // range minimum query
int rmxi[MAXN][LOG2NF+1]; // range maximum index
int rmni[MAXN][LOG2NF+1]; // range mimimum index

int anchors[MAXN];
int acnt;

int log2nf(int x) {
	int cnt = 0;
	while (x > 1) {
		x >>= 1;
		++cnt;
	}

	return cnt;
}

int log2nf(int x, int &v) {
	int cnt = 0;
	v = 1;
	while (x > 1) {
		x >>= 1;
		++cnt;
		v <<= 1;
	}

	return cnt;
}

int findMinIdx(int l, int r) {
	int len = r - l/* + 1*/, t;
	int log2n = log2nf(len, t);
	if (rmnq[l][log2n] < rmnq[r-t+1][log2n]) {
		return rmni[l][log2n];
	} else {
		return rmni[r-t+1][log2n];
	}
}

int findMaxIdx(int l, int r) {
	int len = r - l/* + 1*/, t;
	int log2n = log2nf(len, t);
	if (rmxq[l][log2n] > rmxq[r-t+1][log2n]) {
		return rmxi[l][log2n];
	} else {
		return rmxi[r-t+1][log2n];
	}
}

void findAnchor(int l, int r, bool mx) {
	if (r < l) { return; }
	if (l == r) {
		anchors[acnt++] = l;
		return;
	}

	int anchor = mx ? findMaxIdx(l, r) : findMinIdx(l, r);
	anchors[acnt++] = anchor;
	if (l == 0) {
		findAnchor(l, anchor-1, !mx);
	} else {
		findAnchor(anchor+1, r, !mx);
	}
}

int main() {
	int n; scanf("%d", &n);
	for (int i=0; i<n; ++i) {
		int v; scanf("%d", &v);
		rmxq[i][0] = rmnq[i][0] = v;
		rmxi[i][0] = rmni[i][0] = i;
	}

	if (n == 1) {
		printf("1\n1\n");
		return 0;
	}

	int log2n = log2nf(n);
	for (int i=1, len=1; i<=log2n; ++i, len+=len) {
		for (int i2=0, end=n-len-len; i2<=end; ++i2) {
			int right = i2 + len;

			if (rmxq[i2][i-1] > rmxq[right][i-1]) {
				rmxq[i2][i] = rmxq[i2][i-1];
				rmxi[i2][i] = rmxi[i2][i-1];
			} else {
				rmxq[i2][i] = rmxq[right][i-1];
				rmxi[i2][i] = rmxi[right][i-1];
			}

			if (rmnq[i2][i-1] < rmnq[right][i-1]) {
				rmnq[i2][i] = rmnq[i2][i-1];
				rmni[i2][i] = rmni[i2][i-1];
			} else {
				rmnq[i2][i] = rmnq[right][i-1];
				rmni[i2][i] = rmni[right][i-1];
			}
		}
	}

	acnt = 0;
	int mni = findMinIdx(0, n-1);
	int mxi = findMaxIdx(0, n-1);
	anchors[acnt++] = mni;
	anchors[acnt++] = mxi;

	if (mni > mxi) {
		findAnchor(mni+1, n-1, true);
		findAnchor(0, mxi-1, false);
	} else {
		findAnchor(0, mni-1, true);
		findAnchor(mxi+1, n-1, false);
	}

	sort(anchors, anchors+acnt);
	printf("%d\n", acnt);

	for (int i=0; i<acnt; ++i) {
		printf(i==0 ? "%d" : " %d", anchors[i]+1);
	}

	printf("\n");

	return 0;
}
