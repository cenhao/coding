#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	vector<string> invalidTransactions(vector<string>& transactions) {
		vector<vector<string>> rts;
		for (auto &t: transactions) {
			string buf;
			vector<string> rt;
			for (int i=0; i<=t.length(); ++i) {
				if (i==t.length() || t[i]==',') {
					rt.emplace_back(move(buf));
				} else {
					buf += t[i];
				}
			}

			rts.emplace_back(move(rt));
		}

		vector<bool> valid(transactions.size(), true);
		for (int i=0; i<rts.size(); ++i) {
			if (stoi(rts[i][2]) > 1000) {
				valid[i] = false;
				continue;
			}
			for (int j=0; j<rts.size(); ++j) {
				if (i == j) { continue; }
				if (rts[i][0] == rts[j][0] && rts[i][3] != rts[j][3]) {
					int t1 = stoi(rts[i][1]), t2 = stoi(rts[j][1]);
					if (abs(t1-t2) <= 60) {
						valid[i] = valid[j] = false;
					}
				}

			}
		}
		vector<string> ans;
		for (int i=0; i<transactions.size(); ++i) {
			if (!valid[i]) { ans.emplace_back(transactions[i]); }
		}

		return ans;
	}
};

int main() {
	Solution sol;
	vector<string> in = {string("alice,20,800,mtv"),string("alice,50,100,beijing")};
	auto ans = sol.invalidTransactions(in);
	return 0;
}
