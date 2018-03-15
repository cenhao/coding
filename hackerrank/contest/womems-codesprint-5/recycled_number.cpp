#include <bits/stdc++.h>
using namespace std;

int len(int v) {
	int ret = 1;
	while (v >= 10) {
		++ret;
		v /= 10; 
	}   
	return ret;
}

long uniqueRecycledPairs(vector<int> a) {
	long ans = 0;
	unordered_map<int, int> hm; 
	for (auto av: a) { hm.insert(make_pair(av, 0)); }
	int cn = 0;
	for (auto &p: hm) {
		++cn;
		int v = p.first;
		hm[v] = cn;
		int l = len(v), adj = 1;
		for (int i=0; i<l; ++i) { adj *= 10; }
		unordered_map<int, int>::iterator it;
		for (int i=1, pw = 10; i<l; ++i, pw*=10) {
			int tmp = (v/pw) + (v%pw) * (adj/pw);
			if (tmp > v && (it=hm.find(tmp)) != hm.end() && it->second<cn) {
				it->second = cn;
				++ans;
			}   
		}   
	}   

	return ans;
}

int main() {
	int n; scanf("%d", &n);
	vector<int> a(n);
	for (int i=0; i<n; ++i) { scanf("%d", &a[i]); }
	printf("%ld\n", uniqueRecycledPairs(a));
	return 0;
}
