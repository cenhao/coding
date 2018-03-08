#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int numMatchingSubseq(string S, vector<string>& words) {
		queue<pair<int, int>> q[26];
		int wsz = words.size(), len = S.length();
		vector<int> wlen(wsz);
		for (int i=0; i<wsz; ++i) {
			wlen[i] = words[i].length();
			int idx = words[i][0] - 'a';
			q[idx].push(make_pair(i, 0));
		}

		vector<pair<int, int>> buf(wsz);
		int cnt = 0;
		for (int i=0; i<len; ++i) {
			int idx = S[i] - 'a';
			int tcnt = 0;
			while (!q[idx].empty()) {
				auto p = q[idx].front(); q[idx].pop();
				if (p.second+1 == wlen[p.first]) {
					++cnt;
				} else {
					buf[tcnt++] = make_pair(p.first, p.second+1);
				}
			}

			for (int j=0; j<tcnt; ++j) {
				int sidx = words[buf[j].first][buf[j].second] - 'a';
				q[sidx].push(buf[j]);
			}
		}

		return cnt;
	}
};

int main() {
	string s; cin >> s;
	int n; cin >> n;
	vector<string> v(n);
	for (int i=0; i<n; ++i) { cin >> v[i]; }
	Solution sol;
	cout << sol.numMatchingSubseq(s, v) << endl;
	return 0;
}

