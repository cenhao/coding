#include <bits/stdc++.h>
using namespace std;

#define MAXN 100000

int main() {
	int n; cin >> n;
	unordered_set<string> hs;
	for (int i=0; i<n; ++i) {
		string s; cin >> s;
		int len = s.length();
		int off = s[0] - 'A';
		for (int j=0; j<len; ++j) {
			s[j] = ((s[j]-'A'-off+26) % 26) + 'A';
		}
		hs.insert(move(s));
	}

	int ans = hs.size();
	printf("%d\n", ans);
	return 0;
}
