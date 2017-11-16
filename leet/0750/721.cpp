#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	void dfs(int cur, int id, vector<vector<string>> &acct, unordered_map<string, set<int>> &em, vector<bool> &ck, unordered_map<int, unordered_set<string>> &raw, bool first) {
		ck[cur] = true;
		if (first) { raw.insert(make_pair(id, unordered_set<string>())); }
		for (int i=1; i<acct[cur].size(); ++i) {
			raw[id].insert(acct[cur][i]);
			auto it = em.find(acct[cur][i]);
			for (auto j : it->second) {
				if (ck[j]) { continue; }
				dfs(j, id, acct, em, ck, raw, false);
			}
		}
	}

	vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
		int sz = accounts.size();
		unordered_map<string, set<int>> em;
		vector<bool> ck(sz, false);
		unordered_map<int, unordered_set<string>> raw;

		for (int i=0; i<sz; ++i) {
			int ssz = accounts[i].size();
			int uid = i;
			for (int j=1; j<ssz; ++j) {
				auto it = em.find(accounts[i][j]);
				if (it == em.end()) {
					auto iit = em.insert(make_pair(accounts[i][j], set<int>())).first;
					iit->second.insert(i);
				} else {
					it->second.insert(i);
				}
			}
		}

		vector<string> uname;
		int ucnt = 0;
		for (int i=0; i<sz; ++i) {
			if (ck[i]) { continue; }
			uname.push_back(accounts[i][0]);
			dfs(i, ucnt++, accounts, em, ck, raw, true);
		}

		vector<vector<string>> ans;
		int cnt = 0;
		for (auto ent : raw) {
			ans.push_back(vector<string>());
			ans[cnt].push_back(uname[ent.first]);
			for (auto s : ent.second) {
				ans[cnt].push_back(s);
			}
			sort(ans[cnt].begin(), ans[cnt].end());
			++cnt;
		}

		return ans;
	}
};

int main() {
	int n; cin >> n;
	vector<vector<string>> in;
	for (int i=0; i<n; ++i) {
		int m; cin >> m;
		in.push_back(vector<string>());
		for (int j=0; j<m; ++j) {
			string s; cin >> s; in[i].push_back(s);
		}
	}

	Solution sol;
	sol.accountsMerge(in);
}
