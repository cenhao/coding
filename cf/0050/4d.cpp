#include <bits/stdc++.h>
using namespace std;

#define MAXN 5000

struct Envelope {
	int w, h;
	int id;
} envs[MAXN+1];
int ecnt = 0;

int mnl[MAXN+1];
int mni[MAXN+1];
int idx[MAXN+1];
int val[MAXN+1];
int id[MAXN+1];
int pre[MAXN+1];

int main() {
	int n, cw, ch; scanf("%d %d %d", &n, &cw, &ch);
	for (int i=1; i<=n; ++i) {
		scanf("%d %d", &envs[ecnt].w, &envs[ecnt].h);
		if (envs[ecnt].w > cw && envs[ecnt].h > ch) { envs[ecnt++].id = i; }
	}

	sort(envs, envs+ecnt, [] (const Envelope &e1, const Envelope &e2) -> bool {
		return e1.w == e2.w ? (e1.h < e2.h) : (e1.w < e2.w);
	});

	int mxl = 0, last = -1, buff_size = 0;
	memset(mnl, 0x7f, sizeof(mnl));
	mnl[0] = -1; mni[0] = 0;

	for (int i=0; i<=ecnt; ++i) {
		if (i == ecnt || envs[i].w != last) {
			for (int j=0; j<buff_size; ++j) {
				if (mnl[idx[j]] > val[j]) {
					mnl[idx[j]] = val[j];
					mni[idx[j]] = id[j];
				}
				mxl = max(mxl, idx[j]);
			}

			if (i == ecnt) { break; }

			buff_size = 0;
			last = envs[i].w;
		}

		int l = 0, r = mxl, m;
		while (l <= r) {
			m = (l + r) / 2;
			if (mnl[m] < envs[i].h) {
				l = m + 1;
			} else {
				r = m - 1;
			}
		}

		idx[buff_size] = r + 1;
		id[buff_size] = envs[i].id;
		val[buff_size++] = envs[i].h;
		pre[envs[i].id] = mni[r];
	}

	printf("%d\n", mxl);
	int cur = mni[mxl], cnt = 0;
	while (cur != 0) {
		id[cnt++] = cur;
		cur = pre[cur];
	}

	for (int i=cnt-1; i>=0; --i) {
		printf("%d%c", id[i], (i==0) ? '\n':' ');
	}

	return 0;
}
