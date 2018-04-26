class Solution {
public:
	void push(stack<int> &stk, int v) {
		if (!stk.empty() && (stk.top()=='*'||stk.top()=='/')) {
			bool mul = stk.top() == '*';
			stk.pop();
			v = mul ? stk.top() * v : stk.top() / v;
			stk.pop();
			stk.push(v);
		} else {
			stk.push(v);
		}
	}
	int process(const string &s) {
		stack<int> stk;
		int cur = 0;
		for (int i=0; i<s.length(); ++i) {
			if (s[i] >= '0' && s[i] <= '9') {
				cur = cur * 10 + s[i] - '0';
			} else {
				push(stk, cur);
				cur = 0;
				stk.push(s[i]);
			}
		}
		push(stk, cur);
		int ans = 0;
		while (!stk.empty()) {
			int cur = stk.top();
			stk.pop();
			if (!stk.empty()) {
				cur = stk.top() == '+' ? cur : -cur;
				stk.pop();
			}
			ans += cur;
		}
		return ans;
	}
	int calculate(string s) {
		string ns;
		for (auto c: s) { if (c != ' ') { ns += c; } }
		return process(ns);
	}
};
