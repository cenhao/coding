class Solution {
public:
	void parse(const string &str, int &xcnt, int &v) {
		xcnt = 0; v = 0;
		string ps = str + '$';
		int adj = 1;
		int cur = 0;
		bool any = false;
		for (int i=0, len=ps.length(); i<len; ++i) {
			if (str[i] >= '0' && str[i] <='9') {
				cur = cur * 10 + str[i] - '0';
				any = true;
			} else if (str[i] == 'x') {
				if (any) {
					xcnt += adj * cur;
				} else {
					xcnt += adj * 1;
				}
				cur = 0;
				adj = 1;
				any = false;
			} else {
				v += adj * cur;
				cur = 0;
				adj = (str[i] == '-') ? -1 : 1;
				any = false;
			}
		}
	}

	string solveEquation(string equation) {
		int pos = equation.find("=");
		string left = equation.substr(0, pos);
		string right = equation.substr(pos+1);
		int lxcnt, lv, rxcnt, rv;
		parse(left, lxcnt, lv);
		parse(right, rxcnt, rv);
		lxcnt -= rxcnt;
		rv -= lv;

		if (lxcnt == 0) {
			return rv == 0 ? "Infinite solutions" : "No solution";
		} else {
			char buff[16];
			snprintf(buff, sizeof(buff), "%d", rv / lxcnt);
			string ans = "x=";
			ans += buff;
			return ans;
		}
	}
};
