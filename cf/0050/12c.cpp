#include <bits/stdc++.h>
using namespace std;

#define MAXN 100
#define MAXS 32
char buff[MAXS+1];
int p[MAXN], cnt[MAXN];

int main() {
	int n, m; scanf("%d%d", &n, &m);
	for (int i=0; i<n; ++i) { scanf("%d", &p[i]); }
	sort(p, p+n);
	memset(cnt, 0, sizeof(cnt));
	int id_gen = 0;
	unordered_map<string, int> idmap;
	for (int i=0; i<m; ++i) {
		scanf("%s", buff);
		string sbuff = buff;
		auto it = idmap.find(sbuff);
		if (it == idmap.end()) {
			it = idmap.insert(move(make_pair(move(sbuff), id_gen++))).first;
		}

		++cnt[it->second];
	}
	sort(cnt, cnt+id_gen);

	int mn = 0, mx = 0;
	for (int i=id_gen-1; i>=0; --i) {
		mn += cnt[i] * p[id_gen-i-1];
		mx += cnt[i] * p[n-id_gen+i];
	}

	printf("%d %d\n", mn, mx);
	return 0;
}
