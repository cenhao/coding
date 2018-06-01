#include <bits/stdc++.h>
using namespace std;

/*
using i64 = int64_t;
class Solution {
public:
	i64 calc(const string &exp) {
		stack<i64> stk;
		i64 v = 0;
		bool neg = false, mul = false;
		for (int i=0; i<=exp.length(); ++i) {
			if (i==exp.length() || exp[i]<'0' || exp[i]>'9') {
				if (mul) {
					stk.top() *= v;
				} else {
					stk.push(neg ? -v : v);
				}

				if (i != exp.length()) {
					neg = exp[i] == '-';
					mul = exp[i] == '*';
				}
				v = 0;
			} else {
				v = v * 10 + exp[i] - '0';
			}
		}

		i64 res = 0;
		while (!stk.empty()) { res += stk.top(); stk.pop(); }
		return res;
	}
	void dfs(const string &num, int cur, bool zero, string buf, int target, vector<string> &ans) {
		if (cur >= num.length()) {
			if (calc(buf) == target) { ans.emplace_back(move(buf)); }
			return;
		}

		if (!zero) {
			dfs(num, cur+1, false, buf+num[cur], target, ans);
		} else if (cur == 0) {
			dfs(num, cur+1, num[cur]=='0', buf+num[cur], target, ans);
		}

		if (cur != 0 && buf.back()>='0' && buf.back()<='9') {
			dfs(num, cur+1, num[cur]=='0', buf+"+"+num[cur], target, ans);
			dfs(num, cur+1, num[cur]=='0', buf+"-"+num[cur], target, ans);
			dfs(num, cur+1, num[cur]=='0', buf+"*"+num[cur], target, ans);
		}
	}
	vector<string> addOperators(string num, int target) {
		vector<string> ans;
		dfs(num, 0, true, "", target, ans);
		return ans;
	}
};
*/

using i64 = int64_t;
class Solution {
public:
	void dfs(int start, const string &num, int target, string buf, i64 cv, i64 lv, vector<string> &ans) {
		if (start == num.length()) {
			if (cv == target) { ans.emplace_back(move(buf)); }
			return;
		}
		for (int i=start; i<num.length(); ++i) {
			string sub = num.substr(start, i-start+1);
			i64 v = stol(sub);
			if (to_string(v).length() != sub.length()) { break; }

			if (start == 0) {
				dfs(i+1, num, target, sub, v, v, ans);
			} else {
				dfs(i+1, num, target, buf+"+"+sub, cv+v, v, ans);
				dfs(i+1, num, target, buf+"-"+sub, cv-v, -v, ans);
				dfs(i+1, num, target, buf+"*"+sub, cv-lv+lv*v, lv*v, ans);
			}
		}
	}
	vector<string> addOperators(string num, int target) {
		vector<string> ans;
		dfs(0, num, target, "", 0, 0, ans);
		return ans;
	}
};

int main() {
	string in; cin >> in;
	int tar; cin >> tar;
	Solution sol;
	auto ans = sol.addOperators(in, tar);
	for (auto &a: ans) { cout << a << endl; }
	return 0;
}
