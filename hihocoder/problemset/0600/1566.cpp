#include <bits/stdc++.h>
using namespace std;

#define MAXN 100000

struct People {
	string name;
	string snum;
	int num;
}p[MAXN];

inline int c2i(char c) {
	switch (c) {
		case 'I': return 1;
		case 'V': return 5;
		case 'X': return 10;
		case 'L': return 50;
		case 'C': return 100;
		case 'D': return 500;
		case 'M': return 1000;
	}

	return 0;
}

int s2num(char *s) {
	int len = strlen(s);
	int sum = 0, last = 0;
	for (int i=0; i<len; ++i) {
		int v = c2i(s[i]);
		sum += v;
		if (v > last) { sum -= 2 * last; }
		last = v;
	}

	return sum;
}

int main() {
	int n; scanf("%d", &n);
	char name[32], num[32];
	for (int i=0; i<n; ++i) {
		scanf("%s %s", name, num);
		p[i].name = name;
		p[i].snum = num;
		p[i].num = s2num(num);
	}

	sort(p, p+n, [](const People &p1, const People &p2) {
		return (p1.name != p2.name) ? (p1.name < p2.name) : (p1.num < p2.num);
	});

	for (int i=0; i<n; ++i) {
		printf("%s %s\n", p[i].name.c_str(), p[i].snum.c_str());
	}
	return 0;
}
