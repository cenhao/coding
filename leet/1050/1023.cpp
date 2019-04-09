class Solution {
public:
	vector<bool> camelMatch(vector<string>& queries, string pattern) {
		int sz = queries.size(), plen = pattern.length();
		vector<bool> ans;
		for (auto &q: queries) {
			int pos = 0, len = q.length();
			bool cont = true;
			for (int i=0; cont && i<len; ++i) {
				if (q[i] >= 'a' && q[i] <= 'z') {
					if (pos<plen && q[i]==pattern[pos]) { ++pos; }
				} else {
					if (cont = (pos<plen && q[i]==pattern[pos])) {
						++pos;
					}
				}
			}
			ans.push_back(cont && pos==plen);
		}

		return ans;
	}
};
