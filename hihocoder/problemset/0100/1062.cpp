#include <map>
#include <string>
using namespace std;

#include <stdio.h>
#include <string.h>

#define MAXN 100
int f[MAXN];
char name[MAXN+1];
bool vis[MAXN*10];
string names[MAXN*10];

map<string, int> namemap;
int cnt = -1;

int main() {
	memset(f, -1, sizeof(f));
	int n; scanf("%d", &n);
	for (int i=0; i<n; ++i) {
		scanf("%s", name);
		string sname(name);
		int parent, son;
		map<string, int>::iterator iter = namemap.find(sname);
		if (iter == namemap.end()) {
			namemap.insert(pair<string, int>(sname, ++cnt));
			parent = cnt;
			names[cnt] = sname;
		} else {
			parent = iter->second;
		}
		scanf("%s", name);
		string sname1(name);
		iter = namemap.find(sname1);
		if (iter == namemap.end()) {
			namemap.insert(pair<string, int>(sname1, ++cnt));
			son = cnt;
			names[cnt] = sname1;
		} else {
			son = iter->second;
		}

		f[son] = parent;
	}

	int m; scanf("%d", &m);
	for (int i=0; i<m; ++i) {
		scanf("%s", name);
		int v1, v2;
		string sname(name);
		map<string, int>::iterator iter = namemap.find(sname);
		v1 = (iter == namemap.end()) ? -1 : iter->second;
		scanf("%s", name);
		string sname1(name);
		iter = namemap.find(sname1);
		v2 = (iter == namemap.end()) ? -1 : iter->second;
		memset(vis, 0, sizeof(vis));

		while (v1 != -1) {
			vis[v1] = true;
			v1 = f[v1];
		}

		while (v2 != -1) {
			if (vis[v2]) {
				break;
			}

			v2 = f[v2];
		}

		if (v2 != -1) {
			printf("%s\n", names[v2].c_str());
		} else {
			if (sname == sname1) { printf("%s\n", sname.c_str()); }
			else { printf("-1\n"); }
		}
	}

	return 0;
}
