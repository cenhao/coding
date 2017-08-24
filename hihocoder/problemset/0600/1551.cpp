#include <bits/stdc++.h>
using namespace std;

#define MAXN 500000

char buff[MAXN+1];

struct Node {
	unordered_map<int, int> children;
} nodes[MAXN];
unordered_map<string, int> hm;

int main() {
	int n; scanf("%d", &n);
	int ecnt = 0, ncnt = 1, ans = 0;
	for (int i=0; i<n; ++i) {
		scanf("%s", buff);
		int len = strlen(buff);
		string cur_path;
		int cur_node = 0;
		for (int i=1; i<=len; ++i) {
			if (i == len || buff[i] == '/') {
				if (i == len) {
					break;
				}
				auto it = hm.find(cur_path);
				if (it == hm.end()) {
					it = hm.insert(make_pair(move(cur_path), ecnt++)).first;
				}
				if (nodes[cur_node].children.count(it->second) == 0) {
					nodes[cur_node].children.insert(make_pair(it->second, ncnt++));
					++ans;
				}
				cur_node = nodes[cur_node].children[it->second];
				cur_path = "";
			} else {
				cur_path += buff[i];
			}
		}
	}

	printf("%d\n", ans);
	return 0;
}
