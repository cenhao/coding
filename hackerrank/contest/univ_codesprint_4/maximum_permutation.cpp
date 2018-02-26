#include <bits/stdc++.h>
using namespace std;

#define MAXW 20000
#define MAXS 200000
#define MOD 1000000007
#define PME1 104729
#define PME2 9349 

char w[MAXW+1], s[MAXS+1];
pair<int, int> rng[MAXS];
int cnt[26];

int64_t quick_pow(int64_t v, int p) {
	int64_t ans = 1, base = v;
	while (p > 0) {
		if (p & 1) { ans = (ans * base) % MOD; }
		base = (base * base) % MOD;
		p >>= 1;
	}

	return ans;
}

int main() {
	int q; scanf("%d", &q);
	while (q--) {
		scanf("%s%s", w, s);
		int wlen = strlen(w), slen = strlen(s);
		memset(cnt, 0, sizeof(cnt));
		unordered_map<int64_t, int> hcnt;
		unordered_map<int64_t, pair<int, int>> hvmap;
		for (int i=0; i<wlen; ++i) { ++cnt[w[i]-'a']; }
		int l = 0, r = -1;
		int rcnt = 0;
		for (r=0; r<slen; ++r) {
			int idx = s[r] - 'a';
			--cnt[idx];
			while (cnt[idx]<0 && l<=r) { ++cnt[s[l++]-'a']; }
			if (r-l+1 == wlen) {
				rng[rcnt++] = { l, r };
			}
		}

		if (rcnt == 0) {
			printf("-1\n");
			continue;
		}

		l = r = slen+1;
		int64_t hv[2], pow[2];
		for (int i=rcnt-1; i>=0; --i) {
			if (rng[i].second < l) {
				hv[0] = hv[1] = 0;
				r = rng[i].second;
				l = rng[i].second + 1;
				pow[0] = pow[1] = 1;
			} else {
				int64_t tpow[2] = { 1, 1 };
				while (r > rng[i].second) {
					hv[0] = (hv[0] - (((s[r]-'a')*tpow[0])%MOD) + MOD) % MOD;
					hv[1] = (hv[1] - ((s[r]*tpow[1])%MOD) + MOD) % MOD;
					tpow[0] = (tpow[0] * PME1) % MOD;
					tpow[1] = (tpow[1] * PME2) % MOD;
					--r;
				}

				int64_t tpow_1[2] = { quick_pow(tpow[0], MOD-2), quick_pow(tpow[1], MOD-2) };
				hv[0] = (hv[0] * tpow_1[0]) % MOD;
				hv[1] = (hv[1] * tpow_1[1]) % MOD;
				pow[0] = (pow[0] * tpow_1[0]) % MOD;
				pow[1] = (pow[1] * tpow_1[1]) % MOD;
			}

			while (l > rng[i].first) {
				--l;
				hv[0] = (hv[0] + (s[l]-'a') * pow[0]) % MOD;
				hv[1] = (hv[1] + s[l] * pow[1]) % MOD;
				pow[0] = (pow[0] * PME1) % MOD;
				pow[1] = (pow[1] * PME2) % MOD;
			}

			int64_t tv = hv[0] * MOD + hv[1];
			if (++hcnt[tv] == 1) {
				hvmap[tv] = rng[i];
			}
		}

		int mx = -1;
		for (auto &p: hcnt) { mx = max(mx, p.second); }
		pair<int, int> ans = { -1, -1 };
		map<int, pair<int, int>> candidates;
		for (auto &p: hcnt) {
			if (p.second != mx) { continue; }
			if (ans.first == -1) {
				ans = hvmap[p.first];
			} else {
				auto &tmp = hvmap[p.first];
				for (int i=0; i<wlen; ++i) {
					if (s[ans.first+i] != s[tmp.first+i]) {
						if (s[ans.first+i] > s[tmp.first+i]) { ans = tmp; }
						break;
					}
				}
			}
		}

		for (int i=ans.first; i<=ans.second; ++i) {
			w[i-ans.first] = s[i];
		}

		printf("%s\n", w);
	}

	return 0;
}
