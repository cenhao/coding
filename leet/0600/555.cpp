#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	string getMax(vector<string> &strs, const vector<string> &smxs, int idx) {
		string mxs = ""; int len = strs[idx].length(); string r = "";

		int mx = 0;
		string s = strs[idx];
		for (int i=0; i<s.length(); ++i) { mx = max((int)s[i], mx); }
		for (int i=0; i<len; ++i) {
			if (s[i] != mx) { continue; }
			string tmp = "";
			for (int j=i; j<len; ++j) { tmp += s[j]; }
			for (int j=1; j<strs.size(); ++j) {
				tmp += smxs[(idx+j)%strs.size()];
			}
			for (int j=0; j<i; ++j) { tmp += s[j]; }
			if (tmp > mxs) { mxs = move(tmp); }
		}

		for (int i=len-1; i>=0; --i) { r += s[i]; }
		for (int i=0; i<len; ++i) {
			if (r[i] != mx) { continue; }
			string tmp = "";
			for (int j=i; j<len; ++j) { tmp += r[j]; }
			for (int j=1; j<strs.size(); ++j) {
				tmp += smxs[(idx+j)%strs.size()];
			}
			for (int j=0; j<i; ++j) { tmp += r[j]; }
			if (tmp > mxs) { mxs = move(tmp); }
		}

		return mxs;
	}

	string getSimpleMax(const string &s) {
		string r = "";
		int len = s.length();
		for (int i=len-1; i>=0; --i) { r += s[i]; }
		return (s > r) ? s : r;
	}

	string splitLoopedString(vector<string>& strs) {
		string mxs = "";
		vector<string> smxs(strs.size());
		for (int i=0; i<strs.size(); ++i) {
			smxs[i] = move(getSimpleMax(strs[i]));
		}
		for (int i=0; i<strs.size(); ++i) {
			string tmp = getMax(strs, smxs, i);
			if (tmp > mxs) { mxs = move(tmp); }
		}

		return mxs;
	}
};

int main() {
	int n; cin >> n;
	vector<string> v(n);
	for (int i=0; i<n; ++i) { cin >> v[i]; }
	Solution sol;
	cout << sol.splitLoopedString(v) << endl;
	return 0;
}
