#include <bits/stdc++.h>
using namespace std;

struct QueueItem {
	string s;
	int cnt;
};

string move_str(const string &s, int idx, int tidx) {
	string buff;
	int len = s.length();
	int pos = 0;
	for (int i=0; i<tidx; ++i) {
		if (pos == idx) { pos += 2; }
		buff += s[pos++];
	}
	buff += s[idx]; buff += s[idx+1];
	for (; pos<len; ++pos) {
		if (pos == idx || pos == idx+1) { continue; }
		buff += s[pos];
	}

	return buff;
}

int main() {
	int t; cin >> t;
	while (t--) {
		string s; cin >> s;
		int len = s.length();
		string tar = "";
		for (int i=1; i<=len; ++i) { tar += '0' + i; }
		if (s == tar) {
			printf("0\n");
			continue;
		}
		unordered_map<string, int> hm;
		hm.insert(make_pair(s, 0));
		QueueItem tmp, tmp1;
		tmp.s = s; tmp.cnt = 0;
		queue<QueueItem> q;
		q.push(tmp);

		int ans = -1;
		while (!q.empty() && ans == -1) {
			tmp = q.front(); q.pop();
			tmp1.cnt = tmp.cnt + 1;
			for (int i=len-2; i>=0 && ans == -1; --i) {
				for (int j=0; j<len-1; ++j) {
					if (j == i) { continue; }
					tmp1.s = move_str(tmp.s, i, j);
					if (tmp1.s == tar) {
						ans = tmp1.cnt;
						break;
					}
					auto it = hm.find(tmp1.s);
					if (it == hm.end()) {
						hm.insert(make_pair(tmp1.s, tmp1.cnt));
						q.push(tmp1);
					}
				}
			}
		}

		printf("%d\n", ans);
	}

	return 0;
}
