#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

class Solution {
	public:
		string intToRoman(int num) {
			int range[] = { 1, 10, 100, 1000 };
			char numerals[] = { 'I', 'V', 'X', 'L', 'C', 'D', 'M' };

			string result = "";

			for (int i=0; num>0; ++i) {
				int v = num % 10;
				num /= 10;
				int low = v % 5;
				bool adv = v >= 5;
				if (low == 4) {
					result += numerals[i*2+(adv ? 2:1)];
					result += numerals[i*2];
				} else {
					for (int j=0; j<low; ++j) { result += numerals[i*2]; }
					if (adv) { result += numerals[i*2+1]; }
				}
			}

			reverse(result.begin(), result.end());
			return result;
		}
};

int main() {
	Solution sol;
	int n;
	while (cin >> n) {
		cout << sol.intToRoman(n) << endl;
	}

	return 0;
}
