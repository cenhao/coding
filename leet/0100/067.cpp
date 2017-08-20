class Solution {
public:
	string addBinary(string a, string b) {
		reverse(begin(a), end(a));
		reverse(begin(b), end(b));
		int la = a.length(), lb = b.length();
		bool carry = false;
		string ans;

		int ia, ib;
		for (ia=0, ib=0; ia<la && ib<lb; ++ia, ++ib) {
			int cnt = (carry ? 1 : 0);
			if (a[ia] == '1') { ++cnt; }
			if (b[ib] == '1') { ++cnt; }
			carry = cnt > 1;
			ans += (cnt & 1) ? '1' : '0';
		}

		for (; ia < la; ++ia) {
			int cnt = (carry ? 1 : 0);
			if (a[ia] == '1') { ++cnt; }
			carry = cnt > 1;
			ans += (cnt & 1) ? '1' : '0';
		}

		for (; ib < lb; ++ib) {
			int cnt = (carry ? 1 : 0);
			if (b[ib] == '1') { ++cnt; }
			carry = cnt > 1;
			ans += (cnt & 1) ? '1' : '0';
		}

		if (carry) { ans += '1'; }

		reverse(begin(ans), end(ans));
		return ans;
	}
};
