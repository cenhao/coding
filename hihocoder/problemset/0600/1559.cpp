#include <bits/stdc++.h>
using namespace std;

#define MAXS 500000

char path[MAXS+1];
struct FS {
	unordered_map<string, int> children;
	int id;
} ent[MAXS];
string buff[MAXS+20];

void dfs(int cur, vector<string> &ans, int cnt, bool is_root) {
	if (ent[cur].id >= 0) {
		for (int i=0; i<cnt; ++i) {
			ans[ent[cur].id] += buff[i];
		}
		return;
	}

	for (auto &kvp : ent[cur].children) {
		buff[cnt] = ((!is_root && ent[cur].children.size() == 1 && ent[kvp.second].id<0) ? '-' : '/');
		buff[cnt+1] = move(kvp.first);
		dfs(kvp.second, ans, cnt+2, false);
	}
}

int main() {
	int n; scanf("%d", &n);
	int ecnt = 1;
	ent[0].id = -1;
	for (int i=0; i<n; ++i) {
		scanf("%s", path);
		int len = strlen(path), cur = 0;
		string cpath;
		for (int j=1; j<=len; ++j) {
			if (j == len || path[j] == '/') {
				auto it = ent[cur].children.find(cpath);
				if (it == ent[cur].children.end()) {
					it = ent[cur].children.insert(make_pair(move(cpath), ecnt++)).first;
				}
				cur = it->second;
				ent[cur].id = -1;
				cpath = "";

				if (j == len) {
					ent[cur].id = i;
				}
			} else {
				cpath += path[j];
			}
		}
	}

	vector<string> ans(n);
	dfs(0, ans, 0, true);
	for (int i=0; i<n; ++i) { printf("%s\n", ans[i].c_str()); }

	return 0;
}
