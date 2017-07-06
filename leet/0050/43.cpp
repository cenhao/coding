class Solution {
public:
	string multiply(string num1, string num2) {
		int len[2] = { num1.length(), num2.length() };
		reverse(num1.begin(), num1.end());
		reverse(num2.begin(), num2.end());
		vector<int> prod(1, 0);
		for (int i=0; i<len[1]; ++i) {
			int mul = num2[i] - '0';
			if (mul == 0) { continue; }
			for (int j=0; j<len[0]; ++j) {
				int tmp = mul * (num1[j] - '0');
				if (tmp == 0) { continue; }
				while (i + j >= prod.size()) {
					prod.push_back(0);
				}
				prod[i+j] += tmp;
			}
			for (int j=0; j<prod.size(); ++j) {
				if (prod[j] >= 10) {
					int add = prod[j] / 10;
					prod[j] %= 10;
					while (j+1 >= prod.size()) {
						prod.push_back(0);
					}
					prod[j+1] += add;
				}
			}
		}

		string ans;
		for (int i=prod.size()-1; i>=0; --i) {
			ans += '0' + prod[i];
		}

		return ans;
	}
};
