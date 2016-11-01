#include <iostream>
#include <string>
using namespace std;

class Solution {
	public:
		int romanToInt(string s) {
			char numerals[] = { 'M', 'D', 'C', 'L', 'X', 'V', 'I' };
			int range[] = { 1000, 500, 100, 50, 10, 5, 1 };

			int last = -1;
			int sum = 0;
			for (int i=0, end=s.length(); i<end; ++i) {
				int idx;
				for (int j=0, jend=sizeof(numerals); j<jend; ++j) {
					if (s[i] == numerals[j]) {
						idx = j;
						break;
					}
				}

				if (idx < last) { sum -= 2 * range[last]; }
				last = idx;
				sum += range[idx];
			}

			return sum;
		}
};

int main() {
	string in;
	Solution sol;
	while (cin >> in) {
		cout << sol.romanToInt(in) << endl;
	}

	return 0;
}
