class Solution {
public:
	vector<int> maxDepthAfterSplit(string seq) {
		int len = seq.length();
		vector<int> ans(len);
		vector<int> cnt(2, 0);
		stack<int> stk;
		for (int i=0; i<len; ++i) {
			char c = seq[i];
			if (c == '(') {
				int v = (cnt[0] > cnt[1]) ? 1 : 0;
				++cnt[v];
				stk.push(v);
				ans[i] = v;
			} else {
				int cur = stk.top(); stk.pop();
				ans[i] = cur;
				--cnt[cur];
			}
		}

		return ans;
	}
};
