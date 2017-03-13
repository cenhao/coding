#include <algorithm>
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
	vector<string> wordsAbbreviation(vector<string>& dict) {
		vector<int> idx(dict.size());
		vector<int> comp_len(dict.size(), 0);
		for (int i=0; i<idx.size(); ++i) { idx[i] = i; }
		sort(idx.begin(), idx.end(), [&] (int a, int b) -> bool {
			int len = dict[a].length();
			if (dict[a].length() != dict[b].length()) {
				return dict[a].length() < dict[b].length();
			} else if (dict[a][len-1] != dict[b][len-1]) {
				return dict[a][len-1] < dict[b][len-1];
			}
			
			int i;
			for (i=0; i<len-1 && dict[a][i]==dict[b][i]; ++i);
			comp_len[a] = max(comp_len[a], i);
			comp_len[b] = max(comp_len[b], i);
			return dict[a][i] < dict[b][i];
		});

		vector<string> ans(dict.size());
		char buff[1024];
		for (int i=0; i<idx.size(); ++i) {
			int abbr = dict[idx[i]].length() - 2 - comp_len[idx[i]];
			int len = snprintf(buff, sizeof(buff), "%d", abbr);

			if (comp_len[idx[i]]+2+len < dict[idx[i]].length()) {
				snprintf(buff, sizeof(buff), "%s%d%c",
						 dict[idx[i]].substr(0, comp_len[idx[i]]+1).c_str(),
						 abbr, dict[idx[i]][dict[idx[i]].length()-1]);
				ans[idx[i]] = buff;
			} else {
				ans[idx[i]] = dict[idx[i]];
			}
		}

		return ans;
	}
};

int main() {
	int n; cin >> n;
	vector<string> v(n);
	for (int i=0; i<n; ++i) { cin >> v[i]; }
	Solution sol;
	sol.wordsAbbreviation(v);
	return 0;
}
