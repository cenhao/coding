class Solution {
public:
	int scoreOfParentheses(string s) {
		stack<int> stk;
		stk.push(0);
		for (auto c: s) {
			if (c == '(') {
				stk.push(0);
			} else {
				int v = max(stk.top()*2, 1); stk.pop();
				stk.top() += v;
			}
		}

		return stk.top();
	}
};
