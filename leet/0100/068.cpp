#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	vector<string> fullJustify(vector<string>& words, int maxWidth) {
		int w = 0, wl = 0, ws = 0;
		vector<string> ans;
		for (int i=0; i<=words.size(); ++i) {
			if (i == words.size() ||
				(w + words[i].length() + (w==0 ? 0 : 1) > maxWidth)) {
				string line;
				if (ws + 1 == i || i == words.size()) {
					for (int j=ws; j<i; ++j) {
						if (j != ws) { line += ' '; }
						line += words[j];
					}
					for (int k=line.length(); k<maxWidth; ++k) {
						line += ' ';
					}
				} else {
					int space = maxWidth - wl;
					int base = space / (i-ws-1), adj = space % (i-ws-1);
					for (int j=ws; j<i; ++j) {
						if (j != ws) {
							for (int k=(adj-->0) ? 0:1; k<=base; ++k) { line += ' '; }
						}
						line += words[j];
					}
				}

				ans.push_back(move(line));
				ws = i; w = 0; wl = 0;
			}

			w += ((w == 0) ? 0 : 1) + words[i].length();
			wl += words[i].length();
		}

		return ans;
	}
};

int main() {
	int n; cin >> n;
	vector<string> v(n);
	for (int i=0; i<n; ++i) { cin >> v[i]; }
	int l; cin >> l;
	Solution sol;
	sol.fullJustify(v, l);
	return 0;
}
