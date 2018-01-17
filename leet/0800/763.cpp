#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	vector<int> partitionLabels(string s) {
		int st[26], ed[26], len = s.length();
		memset(st, 0x7f, sizeof(st));
		memset(ed, -1, sizeof(ed));
		for (int i=0; i<len; ++i) {
			int idx = s[i] - 'a';
			st[idx] = min(st[idx], i);
			ed[idx] = max(ed[idx], i);
		}

		vector<pair<int, int>> itvs;
		for (int i=0; i<26; ++i) {
			if (ed[i] == -1) { continue; }
			itvs.push_back(make_pair(st[i], ed[i]));
		}

		sort(itvs.begin(), itvs.end());
		int sz = itvs.size();

		vector<int> ans;
		int last = -1, right = -1;
		for (int i=0; i<sz; ++i) {
			if (itvs[i].first > right) {
				if (right >= 0) {
					ans.push_back(right - last);
					last = right;
				}
			}

			right = max(right, itvs[i].second);
		}

		if (right >= 0) { ans.push_back(right-last); }
		return ans;
	}
};

int main() {
	string s; cin >> s;
	Solution sol;
	sol.partitionLabels(s);
	return 0;
}
