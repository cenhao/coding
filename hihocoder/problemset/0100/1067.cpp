#include <cstdio>
#include <cstring>
#include <map>
#include <string>
using namespace std;

#define MAXN 100000
#define MAXM 100000

struct Node {
	int cn;
	int nxt;
} people[MAXN+10];

struct QNode {
	int cn;
	int qn;
	int nxt;
} query[2*MAXM+10];

string names[MAXN+10];

int idc;
int first;

int state[MAXN+10];
int f[MAXN+10];
int link[MAXN+10];
int qlink[MAXN+10];
int ans[MAXM+10];

char name[2][100];

map<string, int> namemap;

int toId(char *name) {
	string sname = string(name);
	map<string, int>::iterator it;
	it = namemap.find(sname);
	int id;

	if (it == namemap.end()) {
		id = idc++;
		namemap.insert(pair<string, int>(sname, id));
		names[id] = sname;
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

void merge(int id1, int id2) {
	int g2 = find(id2);
	f[g2] = id1;
}

void process(int sta) {
	state[sta] = 1;
	f[sta] = sta;
	for (int i=qlink[sta]; i!=-1; i=query[i].nxt) {
		int cn = query[i].cn;
		if (state[cn] == 1) {
			ans[query[i].qn] = cn;
		} else if (state[cn] == 2) {
			ans[query[i].qn] = find(cn);
		}
	}

	for (int i=link[sta]; i!=-1; i=people[i].nxt) {
		int cn = people[i].cn;
		process(cn);
		merge(sta, cn);
	}

	state[sta] = 2;
}

void process() {
	memset(state, 0, sizeof(state));
	process(0);
}

int main() {
	memset(link, -1, sizeof(link));
	int n; scanf("%d", &n);
	idc = 0;
	first = 0;
	for (int i=0; i<n; ++i) {
		scanf("%s %s", name[0], name[1]);
		int id1 = toId(name[0]), id2 = toId(name[1]);
		people[first].cn = id2; people[first].nxt = link[id1]; link[id1] = first++;
	}

	memset(qlink, -1, sizeof(qlink));
	int m; scanf("%d", &m);
	first = 0;
	for (int i=0; i<m; ++i) {
		scanf("%s %s", name[0], name[1]);
		int id1 = toId(name[0]), id2 = toId(name[1]);
		query[first].cn = id2; query[first].qn = i;
		query[first].nxt = qlink[id1]; qlink[id1] = first++;
		if (id1 != id2) {
			query[first].cn = id1; query[first].qn = i;
			query[first].nxt = qlink[id2]; qlink[id2] = first++;
		}
	}

	process();

	for (int i=0; i<m; ++i) {
		printf("%s\n", names[ans[i]].c_str());
	}

	return 0;
}
