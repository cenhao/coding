#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	struct Node {
		char v;
		unordered_set<int> in, out;
	};
	bool active[26];
	void process(const vector<string> &w, vector<Node> &nodes, int p, int st, int ed) {
		if (st == ed-1) { return; }
		int lv = -1, lp = -1;
		for (int i=st; i<=ed; ++i) {
			if (i==ed || (p<w[i].length() && w[i][p]!=lv+'a')) {
				if (lv != -1) { process(w, nodes, p+1, lp, i); }
				if (i != ed) {
					int cur = w[i][p] - 'a';
					if (lv != -1) {
						nodes[lv].out.insert(cur);
						nodes[cur].in.insert(lv);
					}
					lv = cur;
				}
				lp = i;
			}
		}
	}
	string alienOrder(vector<string>& words) {
		int sz = words.size();
		memset(active, 0, sizeof(active));
		vector<Node> nodes(26);
		process(words, nodes, 0, 0, sz);
		queue<int> q;
		int cnt = 0;
		for (auto &w: words) {
			for (auto c: w) { active[c-'a'] = true; }
		}
		for (int i=0; i<26; ++i) {
			if (active[i]) {
				++cnt;
				if (nodes[i].out.size() == 0) {
					q.push(i);
				}
			}
		}

		string ans = "";
		while (!q.empty()) {
			int tmp = q.front(); q.pop();
			ans += 'a' + tmp;
			--cnt;
			for (auto p: nodes[tmp].in) {
				nodes[p].out.erase(tmp);
				if (nodes[p].out.size() == 0) { q.push(p); }
			}
		}

		if (cnt != 0) { return ""; }
		reverse(ans.begin(), ans.end());
		return ans;
	}
};

int main() {
	int n; cin >> n;
	vector<string> w(n);
	for (int i=0; i<n; ++i) { cin >> w[i]; }
	Solution sol;
	cout << sol.alienOrder(w) << endl;
	return 0;
}
