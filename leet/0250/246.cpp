class Solution {
public:
	bool isStrobogrammatic(string num) {
		const static char conv[10] = {
			'0', '1', 'x', 'x', 'x', 'x', '9', 'x', '8', '6'
		};

		string tmp;
		for (int i=num.size()-1; i>=0; --i) {
			tmp += conv[num[i]-'0'];
		}
		return tmp == num;
	}
};
