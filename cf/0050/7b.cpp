#include <bits/stdc++.h>
using namespace std;

map<int, int> mem;
unordered_map<int, pair<int, int>> alloced;
int id = 1, m;

void alloc() {
	int n; scanf("%d", &n);
	for (auto it=mem.begin(); it!=mem.end(); ++it) {
		if (it->second-it->first+1 >= n) {
			alloced.insert(make_pair(id, make_pair(it->first, it->first+n-1)));
			int left = it->second-it->first+1-n;
			int start = it->first + n;
			mem.erase(it);
			if (left > 0) { mem.insert(make_pair(start, start+left-1)); }
			printf("%d\n", id++);
			return;
		}
	}

	printf("NULL\n");
}

void erase() {
	int n; scanf("%d", &n);
	auto it = alloced.find(n);
	if (it == alloced.end()) {
		printf("ILLEGAL_ERASE_ARGUMENT\n");
		return;
	}

	int start = it->second.first, end = it->second.second;
	alloced.erase(it);

	auto fit = mem.lower_bound(start);
	if (fit != mem.end() && fit->first == end+1) {
		end = fit->second;
		if (fit != mem.begin()) {
			auto pfit = prev(fit);
			if (pfit->second + 1 == start) {
				start = pfit->first;
				mem.erase(pfit, fit);
			} else {
				mem.erase(fit);
			}
		} else {
			mem.erase(fit);
		}
	}

	mem.insert(make_pair(start, end));
}

void defragment() {
	vector<pair<int, pair<int, int>>> v(alloced.size());
	int cnt = 0;
	for (auto &ent : alloced) { v[cnt++] = ent; }
	alloced.clear();
	sort(v.begin(), v.end(), [](const pair<int, pair<int, int>> &p1, const pair<int, pair<int, int>> &p2) {
		return p1.second.first < p2.second.first;
	});

	int start = 1;
	for (auto ent : v) {
		int end = start + ent.second.second - ent.second.first;
		ent.second.first = start; ent.second.second = end;
		alloced.insert(move(ent));
		start = end + 1;
	}

	mem.clear();
	if (start <= m) { mem.insert(make_pair(start, m)); }
}

int main() {
	int t; scanf("%d %d", &t, &m);
	mem.insert(make_pair(1, m));

	for (int i=0; i<t; ++i) {
		static char op[16]; scanf("%s", op);

		if (op[0] == 'a') {
			alloc();
		} else if (op[0] == 'd') {
			defragment();
		} else {
			erase();
		}
	}
}
