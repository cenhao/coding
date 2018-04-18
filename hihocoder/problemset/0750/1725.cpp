#include <bits/stdc++.h>
using namespace std;

#define MAXN 20000
string strs[MAXN];

int main() {
	int n; scanf("%d", &n);
	unordered_set<string> hs;
	for (int i=0; i<n; ++i) {
		cin >> strs[i];
		hs.insert(strs[i]);
	}

	int ans = 0;
	for (int i=0; i<n; ++i) {
		int len = strs[i].length();
		for (int j=0; j<len; ++j) {
			for (int k=j+1; k<len; ++k) {
				if (strs[i][j] == strs[i][k]) { continue; }
				swap(strs[i][j], strs[i][k]);
				if (hs.find(strs[i]) != hs.end()) { ++ans; }
				swap(strs[i][j], strs[i][k]);
			}
		}
	}
	printf("%d", ans>>1);
	return 0;
}
