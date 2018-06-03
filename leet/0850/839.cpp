class Solution {
public:
	int get(int x, vector<int> &f) {
		return f[x] = (f[x] == f[f[x]] ? f[x] : get(f[x], f));
	}
	int numSimilarGroups(vector<string>& a) {
		int sz = a.size();
		vector<int> f(sz);
		for (int i=0; i<sz; ++i) { f[i] = i; }

		for (int i=0; i<sz; ++i) {
			for (int j=i+1; j<sz; ++j) {
				int p1 = get(i, f), p2 = get(j, f);
				if (p1 == p2) { continue; }
				int cnt = 0, p[2];
				for (int k=0; k<a[i].length() && cnt<=2; ++k) {
					if (a[i][k] != a[j][k]) {
						if (cnt < 2) { p[cnt] = k; }
						++cnt;
					}
				}

				if (cnt != 2) { continue; }
				if (a[i][p[0]] != a[j][p[1]] || a[i][p[1]] != a[j][p[0]]) { continue; }
				f[p2] = p1;
			}
		}

		unordered_set<int> hs;
		for (int i=0; i<sz; ++i) {
			hs.insert(get(i, f));
		}

		return hs.size();
	}
};
