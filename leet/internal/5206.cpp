class Solution {
public:
	string removeDuplicates(string s, int k) {
		stack<pair<char, int>> stk;
		for (auto c: s) {
			if (stk.empty() || stk.top().first!=c) {
				stk.push(make_pair(c, 1));
			} else {
				++stk.top().second;
			}

			if (stk.top().second >= k) { stk.pop(); }
		}

		string ans;
		while (!stk.empty()) {
			auto tmp = stk.top(); stk.pop();
			for (int i=0; i<tmp.second; ++i) { ans += tmp.first; }
		}

		reverse(ans.begin(), ans.end());
		return ans;
	}
};
