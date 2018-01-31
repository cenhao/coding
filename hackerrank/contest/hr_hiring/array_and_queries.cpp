/*
 * The key to the problem is to find f(A)
 * f(A) = $$sum_{i=min}^{max}(max(0, cnt[i]-cnt[i-1]))$$
 *
 * Once this formula is understood, the problem becomes how to calculate
 * it efficiently. In fact, there's no need to calculate every number,
 * a unordered_map can be used to store the occurence of each integer that
 * is in the array, and we can enumerate the all the elements in the map,
 * for each element, try to find its previous integer's occurence.
 *
 * After enumerating the whole map, we have the initial f.
 *
 * Then for each query, just calculate the change in f.
 */
#include <bits/stdc++.h>
using namespace std;

#define MAXN 300000
#define MOD 1000000007
int a[MAXN+1];

int main() {
	int n; scanf("%d", &n);
	unordered_map<int, int> cnt;
	for (int i=1; i<=n; ++i) {
		scanf("%d", &a[i]);
		++cnt[a[i]];
	}

	int64_t f = 0;
	for (auto c : cnt) {
		int pc = 0;
		auto it = cnt.find(c.first-1);
		if (it != cnt.end()) { pc = it->second; }
		f += max(0, c.second-pc);
	}

	int64_t ans = 0;
	int q; scanf("%d", &q);
	for (int i=1; i<=q; ++i) {
		int id, v; scanf("%d%d", &id, &v);

		int ov = a[id];
		auto pit = cnt.find(ov-1);
		auto nit = cnt.find(ov+1);
		int pv = pit == cnt.end() ? 0 : pit->second;
		int nv = nit == cnt.end() ? 0 : nit->second;
		int origin = max(0, cnt[ov]-pv) + max(0, nv-cnt[ov]);
		int cv = --cnt[a[id]];
		if (cnt[a[id]] == 0) { cnt.erase(a[id]); }
		int now = max(0, cv-pv) + max(0, nv-cv);
		f += now - origin;

		a[id] = v;
		pit = cnt.find(v-1);
		nit = cnt.find(v+1);
		pv = pit == cnt.end() ? 0 : pit->second;
		nv = nit == cnt.end() ? 0 : nit->second;
		origin = max(0, cnt[v]-pv) + max(0, nv-cnt[v]);
		++cnt[v];
		now = max(0, cnt[v]-pv) + max(0, nv-cnt[v]);
		f += now - origin;
		ans = (ans + ((f * i) % MOD)) % MOD;
	}

	printf("%" PRId64 "\n", ans);
	return 0;
}
