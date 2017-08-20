class Solution {
public:
	bool isNumber(string s) {
		int len = s.length();
		int cur = 0;

		while (cur < len && s[cur] == ' ') { ++cur; }
		if (cur < len && (s[cur] == '+' || s[cur] == '-')) { ++cur; }

		bool any_v = false;
		while (cur < len && s[cur] >= '0' && s[cur] <= '9') { ++cur; any_v = true; }

		if (cur < len &&  s[cur] == '.') {
			++cur;
			while (cur < len && s[cur] >= '0' && s[cur] <= '9') { ++cur; any_v = true; }
		}

		if (!any_v) { return false; }

		if (cur < len && s[cur] == 'e') {
			++cur;
			if (cur < len && (s[cur] == '+' || s[cur] == '-')) { ++cur; }
			bool any_ev = false;
			while (cur < len && s[cur] >= '0' && s[cur] <= '9') { ++cur; any_ev = true; }
			if (!any_ev) { return false; }
		}

		while (cur < len && s[cur] == ' ') { ++cur; }
		return cur >= len;
	}
};
