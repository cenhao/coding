class Solution {
public:
	static int gcd(int a, int b){
		while (b != 0) {
			int tmp = b;
			b = a % b;
			a = tmp;
		}
		return a;
	}

	static int readNextVal(const string &exp, int start, int &num, int &dom) {
		if (start > exp.length()) { return -1; }
		num = dom = 0;
		bool neg = false;

		if (exp[start++] == '-') { neg = true; }
		while (exp[start] != '/') {
			num = num * 10 + exp[start++] - '0';
		}

		++start; // skip /
		while (start < exp.length() && exp[start] >= '0' && exp[start] <= '9') {
			dom = dom * 10 + exp[start++] - '0';
		}

		int g = gcd(num, dom);
		num /= g; dom /= g;
		if (neg) { num = -num; }
		return start;
	}

	string fractionAddition(string expression) {
		int num = 0, dom = 1;
		if (expression[0] >= '0' && expression[0] <= '9') {
			expression = move('+' + move(expression));
		}

		int start = 0;
		do {
			int nn, nd;
			start = readNextVal(expression, start, nn, nd);
			int g = gcd(dom, nd);
			int m1 = nd / g, m2 = dom / g;
			num = m1 * num + m2 * nn;
			dom = dom * m1;
			g = gcd(abs(num), dom);
			num /= g; dom /= g;
		} while (start < expression.length());
		char buff[64];
		snprintf(buff, sizeof(buff), "%d/%d", num, dom);
		return string(buff);
	}
};
