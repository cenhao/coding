#include <bits/stdc++.h>
using namespace std;

int giftBoxes(string g, string c) {
	int glen = g.length();
	vector<int> fail(glen, -1);
	for (int i=1, p=-1; i<glen; ++i) {
		while (p!=-1 && g[p+1]!=g[i]) { p = fail[p]; }
		if (g[p+1] == g[i]) { fail[i] = ++p; }
	}

	int clen = c.length(), ans = 0;
	stack<int> stk;
	for (int i=0, p=-1, head=-1, pi=-1; i<clen; ++i) {
		while (p!=-1 && g[p+1]!=c[i]) { p = fail[p]; }
		if (g[p+1] == c[i]) {
			stk.push(++p);
			if (p == glen-1) {
				++ans;
				for (int j=0; j<glen; ++j) { stk.pop(); }
				p = stk.empty() ? -1 : stk.top();
			}
		} else {
			stk = stack<int>();
		}
	}

	return ans;
}

int main() {
	int t; cin >> t;
	while (t--) {
		string g, c; cin >> g >> c;
		cout << giftBoxes(move(g), move(c)) << endl;
	}

	return 0;
}
