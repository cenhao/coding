class Solution {
public:
	string decodeAtIndex(string s, int k) {
		int len = s.length();
		stack<pair<int, int64_t>> stk;
		stk.emplace(-1, 0);
		vector<int64_t> dp(len+1, 0);
		for (int i=0; i<len && stk.top().second<k; ++i) {
			int64_t v;
			if (s[i]>='a' && s[i]<='z') {
				v = stk.top().second + 1;
			} else {
				v = stk.top().second * (s[i]-'0');
			}
			stk.emplace(i, v);
		}

		int pos;
		do {
			k = k % stk.top().second;
			pos = stk.top().first;
			stk.pop();
		} while (k!=0 || s[pos]<'a' || s[pos]>'z');
		return s.substr(pos, 1);
	}
};
