#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	struct FuncStatus {
		bool is_start;
		int id, ts;
	};

	int dfs(int &cur, const vector<FuncStatus> &fs, vector<int> &cnt) {
		int cid = fs[cur].id;
		int start = fs[cur++].ts;
		int used = 0;
		for (; cur<fs.size(); ++cur) {
			if (fs[cur].id != cid || fs[cur].is_start) {
				used += dfs(cur, fs, cnt);
			} else {
				break;
			}
		}

		cnt[cid] += fs[cur].ts - start + 1 - used;
		return fs[cur].ts - start + 1;
	}

	void process(const string &s, int &id, bool &is_start, int &ts) {
		id = ts = 0;
		is_start = false;
		bool is_id = true;
		for (int i=0; i<s.length(); ++i) {
			if (s[i] >= '0' && s[i] <= '9') {
				if (is_id) {
					id = id * 10 + s[i] - '0';
				} else {
					ts = ts * 10 + s[i] - '0';
				}
			} else {
				if (s[i] == 's') {
					is_start = true;
				}
				is_id = false;
			}
		}
	}
	vector<int> exclusiveTime(int n, vector<string>& logs) {
		int sz = logs.size();
		vector<FuncStatus> fs(sz);
		vector<int> cnt(n, 0);

		char buff[16];
		int id, ts;
		for (int i=0; i<sz; ++i) {
			sscanf(logs[i].c_str(), "%d:%s:%d", &id, buff, &ts);
			process(logs[i], fs[i].id, fs[i].is_start, fs[i].ts);
		}

		sort(fs.begin(), fs.end(), [](const FuncStatus &f1, const FuncStatus &f2) {
			return (f1.ts != f2.ts) ? (f1.ts < f2.ts) : (f1.is_start);
		});

		int cur = 0;
		while (cur < sz) {
			dfs(cur, fs, cnt);
			++cur;
		}
		return cnt;
	}
};

int main() {
	int n, m; cin >> n >> m;
	vector<string> logs(m);
	for (int i=0; i<m; ++i) { cin >> logs[i]; }
	Solution sol;
	vector<int> ans = sol.exclusiveTime(n, logs);
	for (int i=0; i<n; ++i) { cout << ans[i] << endl; }
	return 0;
}
