class Solution {
public:
	int evalRPN(vector<string>& tokens) {
		stack<int> stk;
		int ans = 0;
		for (auto &t: tokens) {
			if (t.length() > 1 || (t[0] >= '0' && t[0] <= '9')) {
				ans = stoi(t);
				stk.push(ans);
			} else {
				int rv = stk.top(); stk.pop();
				int lv = stk.top(); stk.pop();
				switch (t[0]) {
					case '+':
						ans = lv + rv;
						break;
					case '-':
						ans = lv - rv;
						break;
					case '*':
						ans = lv * rv;
						break;
					default:
						ans = lv / rv;
				}
				stk.push(ans);
			}
		}
		return ans;
	}
};
