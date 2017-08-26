#include <bits/stdc++.h>
using namespace std;

#define MAXN 200000

struct Show {
	int s, e;
} shows[MAXN];

int main() {
	int n; scanf("%d", &n);
	for (int i=0; i<n; ++i) { scanf("%d%d", &shows[i].s, &shows[i].e); }
	sort(shows, shows+n, [](const Show &s1, const Show &s2) -> bool {
		return s1.s != s2.s ? (s1.s<s2.s) : (s1.e < s2.e);
	});

	bool possible = true;
	priority_queue<int, vector<int>, greater<int>> avai;
	avai.push(0); avai.push(0);
	for (int i=0; i<n; ++i) {
		int nxt = avai.top(); avai.pop();
		if (shows[i].s < nxt) {
			possible = false;
			break;
		}
		avai.push(shows[i].e + 1);
	}

	printf("%s\n", possible ? "YES" : "NO");
	return 0;
}
