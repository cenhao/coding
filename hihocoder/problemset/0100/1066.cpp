#include <map>
#include <string>
using namespace std;

#include <stdio.h>
#include <string.h>

#define MAXN 100000
#define MAXS 100

char name[2][MAXS];
int f[2*MAXN+1];
int s[2*MAXN+1];
int cnt, n;

map<string, int> namemap;

void init() {
	memset(f, 0, sizeof(f));
	memset(s, 0, sizeof(s));
	cnt = 0;
}

int toId(char *name) {
	string sname = string(name);
	int id;
	map<string, int>::iterator it = namemap.find(sname);
	if (it == namemap.end()) {
		id = cnt++;
		namemap.insert(pair<string, int>(sname, id));
		f[id] = id; s[id] = 1;
	} else {
		id = it->second;
	}

	return id;
}

int find(int id) {
	while (f[id] != id) {
		f[id] = f[f[id]];
		id = f[id];
	}

	return id;
}

void merge(int g1, int g2) {
	if (g1 == g2) { return; }
	if (s[g1] >= s[g2]) {
		f[g2] = g1;
	} else {
		f[g1] = g2;
	}
}

int main() {
	for (scanf("%d", &n); n>0; --n) {
		int op; scanf("%d %s %s", &op, name[0], name[1]);
		int g1 = find(toId(name[0])), g2 = find(toId(name[1]));

		if (op == 0) {
			merge(g1, g2);
		} else {
			printf("%s\n", (g1 == g2) ? "yes" : "no");
		}
	}

	return 0;
}
