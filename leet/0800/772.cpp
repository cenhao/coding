#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	void push_stack(stack<pair<int, char>> &stk, int cur) {
		if (!stk.empty() && (stk.top().second == '*' || stk.top().second == '/')) {
			bool mul = stk.top().second == '*';
			stk.pop();
			cur = mul ? stk.top().first * cur : stk.top().first / cur;
			stk.pop();
			stk.push(make_pair(cur, ' '));
		} else {
			stk.push(make_pair(cur, ' '));
		}
	}
	int process(const string &s, int &pos) {
		stack<pair<int, char>> stk;
		int cur = 0;
		for (; pos<s.length() && s[pos]!=')'; ++pos) {
			if (s[pos] == '(') {
				++pos;
				cur = process(s, pos);
			} else {
				if (s[pos] >= '0' && s[pos] <= '9') {
					cur = cur * 10 + s[pos]-'0';
				} else {
					push_stack(stk, cur);
					cur = 0;
					stk.push(make_pair(0, s[pos]));
				}
			}
		}
		push_stack(stk, cur);

		int ans = 0;
		while (!stk.empty()) {
			cur = stk.top().first;
			stk.pop();
			if (!stk.empty()) {
				if (stk.top().second == '-') { cur = -cur; }
				stk.pop();
			}
			ans += cur;
		}
		return ans;
	}
	int calculate(string s) {
		string ns;
		for (auto c: s) { if (c != ' ') { ns += c; } }
		int pos = 0;
		return process(ns, pos);
	}
};

int main() {
	//string s = "((   (   (   4-   2)+ ( 6+   10 )   )+ 1)   /(  (  (   7  +   9 )*   (   5*8)   )-   (  5 +  (   2   *   10   ) ) ) )";
	string s; cin >> s;
	Solution sol;
	cout << sol.calculate(s) << endl;
	return 0;
}
