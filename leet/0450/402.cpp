class Solution {
public:
	string removeKdigits(string num, int k) {
		int len = num.length();
		if (len <= 0) { return "0"; }
		string ans;
		for (int i=0; i<len; ++i) {
			while (!ans.empty() && k>0 && num[i]<ans.back()) {
				ans.pop_back(); --k;
			}
			ans.push_back(num[i]);
		}

		while (k > 0 && !ans.empty()) { --k; ans.pop_back(); }
		int pos = 0;
		while (pos<ans.length() && ans[pos]=='0') { ++pos; }
		ans = ans.substr(pos);
		if (ans.length() == 0) { ans = "0"; }
		return ans;
	}
};
