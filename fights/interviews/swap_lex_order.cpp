#include <bits/stdc++.h>
using namespace std;

string swapLexOrder(string str, vector<vector<int>> pairs) {
	int sz = pairs.size();
	int len = str.length();
	string ret = str;
	unordered_map<int, vector<int>> adj;
	for (int i=0; i<sz; ++i) {
		auto it = adj.find(pairs[i][0]-1);
		if (it == adj.end()) {
			it = adj.insert(make_pair(pairs[i][0]-1, vector<int>())).first;
		}
		it->second.push_back(pairs[i][1]-1);

		it = adj.find(pairs[i][1]-1);
		if (it == adj.end()) {
			it = adj.insert(make_pair(pairs[i][1]-1, vector<int>())).first;
		}
		it->second.push_back(pairs[i][0]-1);
	}

	vector<bool> vis(len, false);
	for (int i=0; i<len; ++i) {
		if (!vis[i] && adj.find(i) != adj.end()) {
			queue<int> q;
			vector<int> idxs;
			q.push(i);
			while (!q.empty()) {
				int cur = q.front(); q.pop();
				if (vis[cur]) { continue; }
				vis[cur] = true;
				idxs.push_back(cur);

				auto it = adj.find(cur);
				for (auto ent : it->second) { if (!vis[ent]) { q.push(ent); } }
			}

			sort(idxs.begin(), idxs.end());
			auto cmp = [&str](int a, int b) { return str[a] < str[b]; };
			priority_queue<int, vector<int>, decltype(cmp)> hp(idxs.begin(), idxs.end(), cmp) ;
			for (auto idx: idxs) {
				int v = hp.top(); hp.pop();
				ret[idx] = str[v];
			}
		}
	}

	return ret;
}

int main() {
	string str; cin >> str;
	int n; cin >> n;
	vector<vector<int>> ps(n, vector<int>(2));
	for (int i=0; i<n; ++i) { cin >> ps[i][0] >> ps[i][1]; }
	cout << swapLexOrder(str, ps) << endl;
	return 0;
}
