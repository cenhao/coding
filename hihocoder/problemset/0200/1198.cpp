#include <bits/stdc++.h>
using namespace std;

#define MAXN 2000
int sz[MAXN], pos[MAXN], freed;

int main() {
	int n, m; scanf("%d %d", &n, &m);
	map<int, int> avai;
	avai.insert(make_pair(0, m));
	freed = -1;

	for (int i=0; i<n; ++i) {
		scanf("%d", &sz[i]);
		int mx = 0;
		auto it = avai.begin();
		for (; it!=avai.end(); ++it) {
			mx = max(mx, it->second);
			if (it->second >= sz[i]) { break; }
		}

		if (it == avai.end()) {
			while (mx < sz[i]) {
				++freed;
				int start = pos[freed], size = sz[freed];
				auto nxt_it = avai.lower_bound(pos[freed]);

				bool bm = false;
				if (nxt_it != avai.end()) {
					if (nxt_it->first == start+size) {
						size += nxt_it->second;
						bm = true;
					}
				}
				if (nxt_it != avai.begin()) {
					auto pre_it = prev(nxt_it);
					if (pre_it->first+pre_it->second == start) {
						start = pre_it->first;
						size += pre_it->second;
						avai.erase(pre_it);
					}
				}

				if (bm) { avai.erase(nxt_it); }
				it = avai.insert(make_pair(start, size)).first;
				mx = max(mx, size);
			}
		}

		pos[i] = it->first;
		int left = it->second - sz[i];
		avai.erase(it);
		if (left > 0) { avai.insert(make_pair(pos[i]+sz[i], left)); }
	}

	for (int i=freed+1; i<n; ++i) {
		printf("%d %d\n", i+1, pos[i]);
	}

	return 0;
}
