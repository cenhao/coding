#include <bits/stdc++.h>
using namespace std;

#define MAXN 100000
#define MAXS 100

char flags[MAXN+10];
char a[MAXS+10], b[MAXS+10];
int faila[MAXS], failb[MAXS];

void kmpinit(char *s, int len, int *fail) {
	fail[0] = -1;
	for (int i=1, pos = -1; i<len; ++i) {
		while (pos != -1 && s[pos+1] != s[i]) { pos = fail[pos]; }
		if (s[pos+1] == s[i]) { ++pos; }
		fail[i] = pos;
	}
}

bool possible(char *s, int lens, int lena, int lenb) {
	int matcha = lens;
	for (int i=0, pos=-1; i<lens; ++i) {
		while (pos != -1 && a[pos+1] != s[i]) { pos = faila[pos]; }
		if (a[pos+1] == s[i]) { ++pos; }
		if (pos == lena - 1) {
			matcha = i;
			break;
		}
	}

	if (matcha >= lens) { return false; }

	for (int i=0, pos=-1; i<lens; ++i) {
		while (pos != -1 && b[pos+1] != s[i]) { pos = failb[pos]; }
		if (b[pos+1] == s[i]) { ++pos; }
		if (pos == lenb - 1) {
			if (i-lenb >= matcha) { return true; }
			pos = failb[pos];
		}
	}

	return false;
}

int main() {
	scanf("%s", flags);
	scanf("%s", a);
	scanf("%s", b);

	int lena = strlen(a), lenb= strlen(b);
	int lenf = strlen(flags);

	kmpinit(a, lena, faila);
	kmpinit(b, lenb, failb);

	bool forward = possible(flags, lenf, lena, lenb);
	reverse(flags, flags+lenf);
	bool backward = possible(flags, lenf, lena, lenb);

	if (forward) {
		printf("%s\n", backward ? "both" : "forward");
	} else {
		printf("%s\n", backward ? "backward" : "fantasy");
	}

	return 0;

}
