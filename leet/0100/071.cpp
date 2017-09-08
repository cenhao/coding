#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	string simplifyPath(string path) {
		vector<string> ent;
		string cur = "";
		for (int i=0; i<=path.length(); ++i) {
			if (i == path.length() || path[i] == '/') {
				if (cur == "..") {
					if (ent.size() > 0) { ent.pop_back(); }
				} else if (cur != "." && cur != "") {
					ent.push_back(move(cur));
				}

				cur = "";
			} else {
				cur += path[i];
			}
		}

		string ans;
		for (auto &e : ent) {
			ans += '/';
			ans += move(e);
		}

		if (ans == "") { ans = "/"; }
		return ans;
	}
};

int main() {
	string in; cin >> in;
	Solution sol;
	cout << sol.simplifyPath(in) << endl;
	return 0;
}
