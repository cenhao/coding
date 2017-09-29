#include <bits/stdc++.h>
using namespace std;

int main() {
	char pwd[3][4];
	for (int i=0; i<3; ++i) { scanf("%s", pwd[i]); }
	bool ok = true;
	for (int i=0; i<3 && ok; ++i) {
		for (int j=0; j<=i && ok; ++j) {
			ok = pwd[2-i][2-j] == pwd[i][j];
		}
	}

	printf("%s", ok ? "YES\n" : "NO\n");
	return 0;
}
