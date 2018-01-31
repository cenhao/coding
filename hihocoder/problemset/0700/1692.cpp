/*
#include <bits/stdc++.h>
using namespace std;

#define MAXN 1000
int p[MAXN];

int main() {
	int n, k; scanf("%d%d", &n, &k);
	for (int i=0; i<n; ++i) { scanf("%d", &p[i]); }
	double l = 0.0, r = 1.0;
	for (int i=0; i<100; ++i) {
		double m = (l+r) / 2;
		int64_t cnt = 0;
		for (int j=0; j<n && cnt<=k; ++j) { cnt += p[j] * m; }
		if (cnt >= k-1) {
			r = m;
		} else {
			l = m;
		}
	}

	double tar = (l+r) / 2;
	int took = 0;
	vector<pair<int, int>> candicates;
	for (int i=0; i<n; ++i) {
		int cn = (tar * p[i]);
		took += cn;
		if (cn+1 < p[i]) {
			candicates.push_back(make_pair(cn+1, p[i]));
		}
	}

	sort(candicates.begin(), candicates.end(), [](const pair<int, int> &p1, const pair<int, int> &p2) {
		return int64_t(p1.first)*p2.second < int64_t(p1.second)*p2.first;
	});

	printf("%d/%d\n", candicates[k-took-1].first, candicates[k-took-1].second);
	return 0;
}
*/

#include <bits/stdc++.h>
using namespace std;

#define MAXN 1000
int p[MAXN];

int64_t find_le_cnt(int n, int num, int dom) {
	int64_t cnt = 0;
	for (int i=0; i<n; ++i) {
		cnt += int64_t(num) * p[i] / dom;
	}
	return cnt;
}

int main() {
	int n, k; scanf("%d%d", &n, &k);
	for (int i=0; i<n; ++i) { scanf("%d", &p[i]); }
	for (int i=0; i<n; ++i) {
		int l = 1, r = p[i]-1;
		while (l <= r) {
			int m = (l+r) >> 1;
			int64_t cnt = find_le_cnt(n, m, p[i]);
			if (cnt == k) {
				printf("%d/%d\n", m, p[i]);
				return 0;
			}

			if (cnt > k) {
				r = m - 1;
			} else {
				l = m + 1;
			}
		}
	}

	return 0;
}
