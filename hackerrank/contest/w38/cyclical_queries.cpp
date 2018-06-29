#include <bits/stdc++.h>
using namespace std;

using pii = pair<int64_t, int>;

#define MAXN 100000
#define MAXSN 400

priority_queue<pii> dpq[MAXN+1];
int64_t tot;
int dist[MAXN+1], nid;
struct Range {
	int64_t sm, mx;
	int ts, pick;
} rng[MAXSN+1];

pii find(int x, int nseg, int sqrtn, int n) {
	int cur_seg = x / sqrtn;
	int64_t mx = -1, fsm = 0, bsm = tot-rng[cur_seg].sm;
	int ts, pick;
	for (int i=x, ed=min(n, (cur_seg+1)*sqrtn); i<ed; ++i) { bsm += dist[i]; }
	for (int i=cur_seg*sqrtn, ed=min(n, (cur_seg+1)*sqrtn); i<ed; ++i) {
		int64_t cur_dist = 0, cur_ts = 0;
		if (!dpq[i].empty()) {
			cur_dist = dpq[i].top().first;
			cur_ts = dpq[i].top().second;
		}

		if (i < x) {
			cur_dist += bsm; bsm += dist[i];
		} else {
			cur_dist += fsm; fsm += dist[i];
		}

		if (cur_dist > mx) {
			mx = cur_dist; ts = cur_ts;
			pick = i;
		} else if (cur_dist==mx && cur_ts>ts) {
			ts = cur_ts;
			pick = i;
		}
	}

	for (int i=(cur_seg+1)%nseg; i!=cur_seg; i=(i+1)%nseg) {
		int64_t cur_dist = rng[i].mx+fsm;
		fsm += rng[i].sm;
		if (cur_dist > mx) {
			mx = cur_dist; ts = rng[i].ts;
			pick = rng[i].pick;
		} else if (cur_dist==mx && rng[i].ts>ts) {
			ts = rng[i].ts;
			pick = rng[i].pick;
		}
	}

	return make_pair(mx, pick);
}

void add(int x, int w, int sqrtn, bool append) {
	int64_t tmpd = dpq[x].empty()||!append ? 0:dpq[x].top().first;
	tmpd += w;
	dpq[x].push(make_pair(tmpd, ++nid));

	int cur_seg = x / sqrtn;
	for (int i=cur_seg*sqrtn; i<x; ++i) { tmpd += dist[i]; }
	if (tmpd >= rng[cur_seg].mx) {
		rng[cur_seg].mx = tmpd;
		rng[cur_seg].ts = nid;
		rng[cur_seg].pick = x;
	}
}

void remove(int x, int sqrtn, int n) {
	dpq[x].pop();
	int cur_seg = x / sqrtn;
	if (x != rng[cur_seg].pick) { return; }
	int64_t sm = 0, mx = -1;
	int ts, pick;
	for (int i=cur_seg*sqrtn, ed=min(n, (cur_seg+1)*sqrtn); i<ed; ++i) {
		int64_t cur_dist = sm, cur_ts = 0;
		sm += dist[i];
		if (!dpq[i].empty()) {
			cur_dist += dpq[i].top().first; cur_ts = dpq[i].top().second;
		}

		if (cur_dist > mx) {
			mx = cur_dist;
			ts = cur_ts;
			pick = i;
		} else if (cur_dist==mx && cur_ts>ts) {
			ts = cur_ts;
			pick = i;
		}
	}
	rng[cur_seg].mx = mx;
	rng[cur_seg].ts = ts;
	rng[cur_seg].pick = pick;
}

int main() {
	int n; scanf("%d", &n);
	for (int i=0; i<n; ++i) { scanf("%d", &dist[i]); }
	nid = tot = 0;
	int sqrtn = sqrt(n);
	int nseg = (n+sqrtn-1) / sqrtn;
	for (int i=0; i<nseg; ++i) {
		rng[i].ts = rng[i].sm = 0;
		for (int j=i*sqrtn, ed=min(n, (i+1)*sqrtn); j<ed; ++j) {
			rng[i].pick = j;
			rng[i].mx = rng[i].sm;
			rng[i].sm += dist[j];
		}
		tot += rng[i].sm;
	}
	int m; scanf("%d", &m);
	for (int i=0; i<m; ++i) {
		int c, x; scanf("%d%d", &c, &x);
		--x;
		if (c == 1) {
			int w; scanf("%d", &w);
			auto p = find(x, nseg, sqrtn, n);
			add(p.second, w, sqrtn, true);
		} else if (c == 2) {
			int w; scanf("%d", &w);
			add(x, w, sqrtn, false);
		} else if (c == 3) {
			auto p = find(x, nseg, sqrtn, n);
			remove(p.second, sqrtn, n);
		} else {
			auto p = find(x, nseg, sqrtn, n);
			printf("%" PRId64 "\n", p.first);
		}
	}

	return 0;
}
