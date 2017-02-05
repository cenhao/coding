#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

#define MAXN 1000

struct Row {
	int self, ext;
	vector<int> vsidx;
} rows[MAXN+1];

struct Section {
	int ext;
	vector<int> vridx;
} sections[MAXN+1];
int scnt = 0;

void read(int ridx) {
	int nrow; scanf("%d", &nrow);
	if (nrow == 0) {
		rows[ridx].self = 1;
		rows[ridx].ext = 0;
		return;
	}

	rows[ridx].self = nrow;
	int cnt = 0, cur_sec = -1;
	bool create_new = true;
	while (cnt < nrow) {
		if (create_new) {
			create_new = false;
			rows[ridx].vsidx.push_back(cur_sec = scnt++);
		}
		int v; scanf("%d", &v);
		if (v == 0) {
			create_new = true;
			continue;
		}
		sections[cur_sec].vridx.push_back(v);
		++cnt;
	}
}

void process(int ridx) {
	for (int i=0, iend=rows[ridx].vsidx.size(); i<iend; ++i) {
		Section &section = sections[rows[ridx].vsidx[i]];
		for (int j=0, jend=section.vridx.size(); j<jend; ++j) {
			process(section.vridx[j]);
		}

		// take the one that's short if put first
		sort(section.vridx.begin(), section.vridx.end(), [](int a, int b) -> bool {
			int mxa = max(rows[a].self, rows[a].ext);
			int mxb = max(rows[b].self, rows[b].ext);
			int afirst = max(mxa, 1+mxb);
			int bfirst = max(mxb, 1+mxa);
			return afirst < bfirst;
		});

		int ext = 0;
		for (int j=0, jend=section.vridx.size(); j<jend; ++j) {
			ext = max(ext, max(rows[section.vridx[j]].self, rows[section.vridx[j]].ext)+j);
		}

		section.ext = ext;
	}

	sort(rows[ridx].vsidx.begin(), rows[ridx].vsidx.end(), [](int a, int b) -> bool {
		int self = sections[a].vridx.size() + sections[b].vridx.size();
		int afirst = max(self, max(sections[a].ext, (int)sections[a].vridx.size()+sections[b].ext));
		int bfirst = max(self, max(sections[b].ext, (int)sections[b].vridx.size()+sections[a].ext));
		return afirst < bfirst;
	});

	int ext = 0, pre = 0;
	for (int i=0, iend=rows[ridx].vsidx.size(); i<iend; ++i) {
		ext = max(ext, sections[rows[ridx].vsidx[i]].ext+pre);
		pre += sections[rows[ridx].vsidx[i]].vridx.size();
	}

	rows[ridx].ext = ext;
}

int main() {
	int n; scanf("%d", &n);
	for (int i=0; i<=n; ++i) { read(i); }
	process(0);
	printf("%d\n", max(rows[0].self, rows[0].ext));
	return 0;
}
