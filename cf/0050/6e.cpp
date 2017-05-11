#include <bits/stdc++.h>
using namespace std;

#define MAXN 100000

int h[MAXN];
int e[MAXN];

struct Book {
	int h, y;
	bool operator < (const Book &b) const { return h < b.h; }
	bool operator > (const Book &b) const { return h > b.h; }
};

int check(int n, int k, int r) {
	priority_queue<Book> mxh;
	priority_queue<Book, vector<Book>, greater<Book>> mnh;

	int cnt = 0;
	for (int i=r-1, pos=0; i<n; ++i) {
		while (pos <= i) {
			Book b = { h[pos], pos };
			mxh.push(b); mnh.push(b);
			++pos;
		}

		while (mxh.top().y < i+1-r) { mxh.pop(); }
		while (mnh.top().y < i+1-r) { mnh.pop(); }

		if (mxh.top().h - mnh.top().h <= k) { e[cnt++] = i+1; }
	}

	return cnt;
}

int main() {
	int n, k; scanf("%d %d", &n, &k);
	for (int i=0; i<n; ++i) { scanf("%d", &h[i]); }

	int l = 1, r = n, cnt;

	while (l <= r) {
		int m = (l + r) >> 1, tmp;

		if ((tmp = check(n, k, m)) > 0) {
			l = m + 1;
			cnt = tmp;
		} else {
			r = m - 1;
		}
	}

	printf("%d %d\n", r, cnt);
	for (int i=0; i<cnt; ++i) { printf("%d %d\n", e[i]-r+1, e[i]); }
	return 0;
}
