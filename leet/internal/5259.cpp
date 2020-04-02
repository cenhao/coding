class Solution {
public:
	double calculateTax(int income, vector<vector<int>>& taxBrackets) {
		double tax = 0.0;
		int prev = 0;
		for (auto &b: taxBrackets) {
			if (b[0] == -1) {
				tax += (income - prev) * b[1] / 100.0;
			} else {
				tax += (min(income, b[0])-prev) * b[1] / 100.0;
			}

			if (b[0]==-1 || b[0]>=income) { break; }
			prev = b[0];
		}

		return tax;
	}
};
