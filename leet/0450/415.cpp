class Solution {
public:
	string addStrings(string num1, string num2) {
		reverse(num1.begin(), num1.end());
		reverse(num2.begin(), num2.end());
		int carry = 0;
		int len1 = num1.length(), len2 = num2.length();
		string ans;
		for (int i=0, ed=max(len1, len2); i<ed; ++i) {
			int v1 = i>=len1 ? 0 : num1[i] - '0';
			int v2 = i>=len2 ? 0 : num2[i] - '0';
			v1 += v2 + carry;
			carry = (v >= 10) ? 1 : 0;
			v1 %= 10;
			ans += '0' + v1;
		}
		if (carry) { ans += '1'; }
		reverse(ans.begin(), ans.end());
		return ans;
	}
};
