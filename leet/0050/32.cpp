class Solution {
public:
	int longestValidParentheses(string s) {
		stack<int> st;
		int mx = 0, buff = -1;
		for (int i=0, len=s.length(); i<len; ++i) {
			if (s[i] == '(') {
				if (buff != -1) {
					st.push(buff);
					buff = -1;
				} else {
					st.push(i);
				}
			} else {
				if (st.empty()) {
					buff = -1;
				} else {
					int top = st.top(); st.pop();
					int tmp = i - top + 1;
					mx = max(tmp, mx);
					buff = top;
				}
			}
		}

		return mx;
	}
};
