#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /**
     * @param target: the target string
     * @param words: words array
     * @return: whether the target can be matched or not
     */
	bool dfs(int cur, int state, const string &tar, const vector<int> &vm) {
		if (cur >= tar.length()) { return true; }
		int need = 1 << (tar[cur]-'a');
		for (int i=0; i<vm.size(); ++i) {
			if (((1<<i)&state) || !(vm[i]&need)) { continue; }
			if (dfs(cur+1, state|(1<<i), tar, vm)) { return true; }
		}
		return false;
	}
    bool matchFunction(string &target, vector<string> &words) {
		int sz = words.size(), len = target.length();
		vector<int> vm(sz, 0);
		for (int i=0; i<sz; ++i) {
			for (auto c: words[i]) { vm[i] |= 1 << (c-'a'); }
		}
		return dfs(0, 0, target, vm);
    }
};

int main() {
	int n; cin >> n;
	vector<string> w(n);
	for (int i=0; i<n; ++i) { cin >> w[i]; }
	string t; cin >> t;
	Solution sol;
	cout << sol.matchFunction(t, w) << endl;
}
