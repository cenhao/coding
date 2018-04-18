#include <bits/stdc++.h>
using namespace std;

/*
class Solution {
public:
	void dfs(const string &s, int p, int len, bool safe, bool add_dot, int idx, vector<char> n[2], vector<string> &ans) {
		if (idx == 1) {
			int last = n[0].size() - 1;
			bool tad = false;
			for (int i=0; i<=last; ++i) {
				if (n[0][i] == '.') { tad = true; break; }
			}
			if (last < 0 || n[0][last]=='.' || (n[0][last]=='0'&&tad)) { return; }
		}
		if (p == len) {
			if (idx==1 && n[1][n[1].size()-1]!='.' && !(add_dot&&n[1][n[1].size()-1]=='0')) {
				string buff = "(";
				string ls;
				for (auto c: n[0]) buff += c;
				buff += ", ";
				for (auto c: n[1]) buff += c;
				buff += ")";
				ans.push_back(move(buff));
			}
			return;
		}

		for (int i=idx; i<2; ++i) {
			bool ok = false;
			bool ns = i==idx ? safe : false, na = i==idx?add_dot:false;
			if (s[p] == '0') {
				if (n[i].size() == 0 || add_dot || safe) {
					ok = true;
				}
			} else {
				if (n[i].size() == 0) {
					ns = ok = true;
				} else if (safe || add_dot) {
					ok = true;
				}
			}

			if (ok) {
				n[i].push_back(s[p]);
				dfs(s, p+1, len, ns, na, i, n, ans);
				n[i].pop_back();
			}

			if (n[i].size()!=0 && !add_dot) {
				n[i].push_back('.');
				dfs(s, p, len, true, true, i, n, ans);
				n[i].pop_back();
			}
		}
	}
	vector<string> ambiguousCoordinates(string s) {
		int len = s.length();
		vector<string> ans;
		vector<char> n[2];
		dfs(s, 1, len-1, false, false, 0, n, ans);
		return ans;
	}
};
*/

class Solution {
public:
	vector<string> extract(const string &s, int st, int ed) {
		vector<string> ret;
		bool left_valid = s[st] != '0', right_valid = s[ed] != '0';
		if (!left_valid) {
			if (!right_valid) {
				if (st == ed) { ret.push_back("0"); }
				return ret;
			}
			string buff(1, s[st]);
			buff += '.';
			for (int i=st+1; i<=ed; ++i) { buff += s[i]; }
			ret.push_back(move(buff));
		} else if (!right_valid) {
			string buff;
			for (int i=st; i<=ed; ++i) { buff += s[i]; }
			ret.push_back(move(buff));
		} else {
			string buff, left;
			for (int i=st; i<=ed; ++i) {
				left += s[i];
				buff = left;
				if (i != ed) { buff += '.'; }
				for (int j=i+1; j<=ed; ++j) {
					buff += s[j];
				}

				ret.push_back(move(buff));
			}
		}
		return ret;
	}

	vector<string> ambiguousCoordinates(string s) {
		int len = s.length();
		vector<string> ans;
		for (int i=1; i<len-2; ++i) {
			vector<string> left = move(extract(s, 1, i));
			if (left.size() == 0) { continue; }
			vector<string> right = move(extract(s, i+1, len-2));
			for (int j=0; j<left.size(); ++j) {
				for (int k=0; k<right.size(); ++k) {
					string buff = "(";
					buff += left[j];
					buff += ", ";
					buff += right[k];
					buff += ")";
					ans.push_back(move(buff));
				}
			}
		}

		return ans;
	}
};


int main() {
	string s; cin >> s;
	Solution sol;
	vector<string> ans = sol.ambiguousCoordinates(s);
	for (auto &as: ans) { cout << as << endl; }
	return 0;
}
