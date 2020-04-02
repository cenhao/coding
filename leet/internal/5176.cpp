#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	vector<int> getHash(string &p) {
		int len = p.length() - 1;
		vector<int> ret (1<<len);
		for (int i=0, ed=1<<len; i<ed; ++i) {
			int v = 0;
			for (int j=0; j<len; ++j) {
				if (i & (1<<j)) { v |= 1 << (p[j+1]-'a'); } 
			}
			ret[i] = v;
		}

		return ret;
	}

	vector<int> findNumOfValidWords(vector<string>& words, vector<string>& puzzles) {
		int psz = puzzles.size();
		unordered_map<int, vector<int>> hm[26];

		for (int i=0; i<puzzles.size(); ++i) {
			string p = move(puzzles[i]);
			auto hv = move(getHash(p));
			for (auto v: hv) { hm[p[0]-'a'][v].emplace_back(i); }
		}

		vector<int> ans(psz, 0);
		for (auto &&w: words) {
			int v = 0;
			for (int i=0; i<w.length(); ++i) { v |= 1 << (w[i]-'a'); }
			for (int i=0; i<26; ++i) {
				if (v & (1<<i)) {
					int vv = v & (~(1<<i));
					auto it = hm[i].find(vv);
					if (it != hm[i].end()) {
						for (auto id: it->second) { ++ans[id]; }
					}
				}
			}
		}

		return ans;
	}
};

int main() {
	vector<string> w = {"aaaa","asas","able","ability","actt","actor","access"};
	vector<string> p = {"aboveyz","abrodyz","abslute","absoryz","actresz","gaswxyz"};
	Solution sol;
	auto ans = sol.findNumOfValidWords(w, p);
	for (auto a: ans) { cout << a << endl; }
	return 0;
}
