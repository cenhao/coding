#include <bits/stdc++.h>
using namespace std;

#define MAXN 1000

int main() {
	int n; cin >> n;
	string winner;
	int mx = -1;
	for (int i=0; i<n; ++i) {
		string name;
		int d, j; cin >> name >> d >> j;
		if (j-d > mx) {
			winner = move(name);
			mx = j-d;
		}
	}

	cout << winner << " " << mx << endl;
	return 0;
}
