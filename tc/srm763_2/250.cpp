class LoopsyDoopsy {
public:
	string getSmallestNumber(int loops) {
		if (loops == 1) { return "0"; }
		string ans = "";
		if (loops & 1) {
			ans += '4';
			--loops;
		}
		while (loops >= 2) {
			ans += '8';
			loops -= 2;
		}
		return ans;
	}
};
