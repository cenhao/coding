class Solution {
public:
	string fractionToDecimal(int numerator, int denominator) {
		int ncnt = 0;
		if (numerator < 0) { ++ncnt; }
		if (denominator < 0) { ++ncnt; }
		bool neg = ncnt == 1;

		int64_t n = abs((int64_t)numerator), d = abs((int64_t)denominator);

		int64_t itg = n / d, rem = n % d;
		string ans = (neg && n!=0 ? "-" : "") + to_string(itg);
		if (rem == 0) { return ans; }

		unordered_map<int64_t, int> hm;

		rem *= 10;
		string dec;
		while (rem!=0 && hm.find(rem)==hm.end()) {
			hm.insert(make_pair(rem, (int)dec.length()));
			int64_t nd = rem / d;
			rem = (rem % d) * 10;
			dec += nd + '0';
		}

		if (rem != 0) {
			int pos = hm[rem];
			dec = dec.substr(0, pos) + "(" + dec.substr(pos) + ")";
		}

		ans += "." + dec;
		return ans;
	}
};
