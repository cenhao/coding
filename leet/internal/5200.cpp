#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	struct Node {
		int v;
		vector<int> children;
	};

	vector<int> topo(vector<Node> &nodes) {
		int sz = nodes.size();
		vector<int> indeg(sz, 0);
		for (auto &node: nodes) {
			for (auto c: node.children) { ++indeg[c]; }
		}

		auto cmp = [](const pair<int, int> &p1, const pair<int, int> &p2) {
			return p1.second > p2.second;
		};

		priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(cmp);
		for (int i=0; i<sz; ++i) { pq.push(make_pair(i, indeg[i])); }

		vector<bool> vis(sz, false);
		vector<int> ret;
		while (ret.size()<sz && !pq.empty()) {
			auto p = pq.top(); pq.pop();
			if (vis[p.first]) { continue; }
			if (p.second != 0) { break; }
			vis[p.first] = true;
			ret.push_back(nodes[p.first].v);
			for (auto c: nodes[p.first].children) {
				pq.push(make_pair(c, --indeg[c]));
			}
		}

		return (ret.size() == sz) ? ret : vector<int>(0);
	}
	vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {
		unordered_map<int, int> tmphm;
		for (int i=0; i<m; ++i) {
			if (group[i] == -1) { continue; }
			auto it = tmphm.find(group[i]);
			if (it == tmphm.end()) {
				int v = tmphm.size();
				tmphm.insert(make_pair(group[i], v));
			}
		}
		for (int i=0; i<m; ++i) {
			if (group[i] == -1) { continue; }
			group[i] = tmphm[group[i]];
		}
		vector<vector<Node>> gn(m);
		vector<int> gindex(n);
		for (int i=0; i<n; ++i) {
			Node node;
			node.v = i;
			if (group[i] == -1) {
				vector<Node> newg(1, node);
				gn.emplace_back(move(newg));
				gindex[i] = 0;
				group[i] = gn.size()-1;
			} else {
				gn[group[i]].emplace_back(node);
				gindex[i] = gn[group[i]].size()-1;
			}
		}

		vector<Node> ggn(gn.size());
		for (int i=0; i<ggn.size(); ++i) { ggn[i].v = i; }
		for (int i=0; i<n; ++i) {
			for (auto b: beforeItems[i]) {
				if (group[b] == group[i]) {
					int gid = group[b];
					gn[gid][gindex[b]].children.push_back(gindex[i]);
				} else {
					int bgid = group[b], igid = group[i];
					ggn[bgid].children.push_back(igid);
				}
			}
		}

		vector<vector<int>> within_g;
		for (int i=0; i<gn.size(); ++i) {
			auto tmp = move(topo(gn[i]));
			if (tmp.size() == 0) { return vector<int>(); }
			within_g.emplace_back(move(tmp));
		}

		auto tmp = move(topo(ggn));
		if (tmp.size() == 0) { return vector<int>(); }
		vector<int> ans;
		for (auto t: tmp) {
			ans.insert(ans.end(), within_g[t].begin(), within_g[t].end());
		}

		return ans;
	}
};

int main() {
	//vector<int> g = { -1,-1,1,0,0,1,0,-1 };
	//vector<vector<int>> bf = { {},{6},{5},{5,6},{3,6},{},{},{}};
	vector<int> g = { 1,0,-1,2,0 };
	vector<vector<int>> bf = { {2,1,3}, {2,4}, {}, {}, {}};
	Solution sol;
	auto ans = sol.sortItems(5, 3, g, bf);
	for (auto a: ans) { cout << a << " "; }
	cout << endl;
	return 0;
}
