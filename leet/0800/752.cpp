class Solution {
public:
	const int mov[4] = {1, 10, 100, 1000};
	const int adj[2] = {1, -1};
	int openLock(vector<string>& deadends, string target) {
		vector<bool> vis(10000, false);
		vector<int> cnt(10000, -1);
		unordered_set<int> de;
		int tar = stoi(target);
		if (tar == 0) { return 0; }
		for (auto &s : deadends) { de.insert(stoi(s)); }
		if (de.end() != de.find(0)) { return -1; }
		vis[0] = true;
		cnt[0] = 0;
		queue<int> q;
		q.push(0);
		while (!q.empty()) {
			int tmp = q.front(); q.pop();
			for (int i=0; i<4; ++i) {
				for (int j=0; j<2; ++j) {
					int m = mov[i] * adj[j];
					int r = (tmp / mov[i]) % 10;
					int tmp1 = tmp + m;;
					if ((r == 0 && adj[j] < 0) || (r == 9 && adj[j] > 0)) {
						tmp1 -= 10 * m;
					}
					if (vis[tmp1] || de.end() != de.find(tmp1)) { continue; }
					cnt[tmp1] = cnt[tmp] + 1;
					vis[tmp1] = true;
					if (tmp1 == tar) { break; }
					q.push(tmp1);
				}
			}
		}

		return cnt[tar];
	}
};
