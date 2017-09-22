#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	void dfs(int sta, int n, vector<int> &ip, vector<string> &ans, const string &s, int len) {
		if (n >= 4 || sta >= len) {
			if (sta == len && n == 4) {
				string buff;
				for (int i=0; i<4; ++i) {
					if (i > 0) { buff += '.'; }
					buff += move(to_string(ip[i]));
				}
				ans.push_back(move(buff));
			}
			return;
		}

		ip[n] = ip[n]*10 + s[sta] - '0';
		if (ip[n] < 256) {
			if (ip[n] > 0) { dfs(sta+1, n, ip, ans, s, len); }
			dfs(sta+1, n+1, ip, ans, s, len);
		}
		ip[n] = (ip[n] - (s[sta]-'0')) / 10;
	}

	vector<string> restoreIpAddresses(string s) {
		vector<int> ip(4, 0);
		vector<string> ans;
		dfs(0, 0, ip, ans, s, s.length());
		return ans;
	}
}; 

int main() {
	string in; cin >> in;
	Solution sol;
	vector<string> ans = sol.restoreIpAddresses(in);
	for (auto &ip : ans) {
		cout << ip << endl;
	}

	return 0;
}
