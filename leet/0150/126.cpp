#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
	void dfs(int cur, int ed, vector<int> &buff, int l,
			 vector<vector<string>> &ans, unordered_map<int, string> &idmap,
			 vector<vector<int>> &reach, vector<int> &step) {
		buff[l] = cur;
		if (cur == ed) {
			vector<string> tmp(l+1);
			for (int i=0; i<=l; ++i) { tmp[i] = idmap[buff[i]]; }
			ans.push_back(move(tmp));
			return;
		}

		for (int i=0; i<reach[cur].size(); ++i) {
			int nxt = reach[cur][i];
			if (step[nxt] == l+2) {
				dfs(nxt, ed, buff, l+1, ans, idmap, reach, step);
			}
		}
	}
	vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
		wordList.push_back(beginWord);
		int sz = wordList.size(), len = beginWord.length();
		unordered_map<int, string> idmap;
		vector<vector<int>> reach(sz, vector<int>());
		int eid = -1;
		for (int i=0; i<sz; ++i) {
			idmap[i] = wordList[i];
			if (wordList[i] == endWord) { eid = i; }
			for (int j=i+1; j<sz; ++j) {
				int cnt = 0;
				for (int k=0; k<len && cnt<=1; ++k) {
					if (wordList[i][k] != wordList[j][k]) { ++cnt; }
				}

				if (cnt == 1) {
					reach[i].push_back(j);
					reach[j].push_back(i);
				}
			}
		}

		vector<vector<string>> ans;
		if (eid == -1) { return ans; }
		if (eid == sz-1) {
			ans.push_back(vector<string>{ beginWord });
			return ans;
		}
		vector<int> step(sz, 0);
		vector<bool> con(sz, false);

		queue<int> fq, bq;
		fq.push(sz-1);
		bq.push(eid);
		step[sz-1] = 1; step[eid] = -1;

		int mnl = -1;
		while (!fq.empty() && !bq.empty() && mnl < 0) {
			queue<int> *qp, tmp;
			int inc;
			if (bq.size() < fq.size()) {
				qp = &bq; inc = -1;
			} else {
				qp = &fq; inc = 1;
			}

			while (!qp->empty()) {
				int cur = qp->front(); qp->pop();
				for (auto i : reach[cur]) {
					if (con[i]) { continue; }
					if (step[i] != 0) {
						if (step[cur] * step[i] < 0) {
							mnl = abs(step[cur]) + abs(step[i]);
							con[i] = true;
						}
						continue;
					}
					step[i] = step[cur] + inc;
					tmp.push(i);
				}

			}
			*qp = move(tmp);
		}

		if (mnl < 0) { return ans; }
		for (int i=0; i<sz; ++i) { if (step[i] < 0) { step[i] += mnl+1; } }
		vector<int> buff(sz);
		dfs(sz-1, eid, buff, 0, ans, idmap, reach, step);
		return ans;
	}
};

int main() {
	int n; cin >> n;
	string b, e; cin >> b >> e;
	vector<string> l(n);
	for (int i=0; i<n; ++i) { cin >> l[i]; }
	Solution sol;
	auto ans = sol.findLadders(b, e, l);
	for (int i=0; i<ans.size(); ++i) {
		for (int j=0; j<ans[i].size(); ++j) {
			cout << ans[i][j] << endl;
		}
		cout << endl;
	}
}
