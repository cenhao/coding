#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, s; scanf("%d%d", &n, &s);
	unordered_map<int, int> hm;
	for (int i=0; i<s; ++i) {
		int l, r; scanf("%d%d", &l, &r);
		int64_t sweet = (int64_t(l)+r) * (r-l+1) / 2;
		unordered_map<int, int>::iterator lit, rit;
		lit = rit = hm.end();
		if (l > 0) {
			lit = hm.find(l-1);
			if (lit == hm.end()) {
				--l; sweet += l;
			} else {
				l = lit->second;
				hm.erase(lit);
				lit = hm.find(l);
				if (l > 0) { --l; sweet += l; }
				hm.erase(lit);
			}
		}
		if (r < n-1) {
			rit = hm.find(r+1);
			if (rit == hm.end()) {
				++r; sweet += r;
			} else {
				r = rit->second;
				hm.erase(rit);
				rit = hm.find(r);
				if (r < n-1) { ++r; sweet += r; }
				hm.erase(rit);
			}
		}
		lit = hm.find(l-1); rit = hm.find(r+1);
		if (lit == hm.end() && rit == hm.end()) {
			hm[l] = r; hm[r] = l;
			hm.insert({l, r}); hm.insert({r, l});
		} else if (lit == hm.end()) {
			r = rit->second;
			hm.erase(rit);
			rit = hm.find(r);
			rit->second = l;
			hm[l] = r;
		} else if (rit == hm.end()) {
			l = lit->second;
			hm.erase(lit);
			lit = hm.find(l);
			lit->second = r;
			hm[r] = l;
		} else {
			l = lit->second;
			hm.erase(lit);
			lit = hm.find(l);
			r = rit->second;
			hm.erase(rit);
			rit = hm.find(r);
			lit->second = r;
			rit->second = l;
		}
		printf("%" PRId64 "\n", sweet);
	}

	return 0;
}
