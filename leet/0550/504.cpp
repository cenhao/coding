#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

class Solution {
	public:
	string convertTo7(int num) {
		if (num == 0) { return "0"; }

		string ans = "";
		bool ne = false;
		if (num < 0) {
			ne = true;
			num = -num;
		}

		while (num > 0) {
			ans += (num % 7) + '0';
			num /= 7;
		}

		if (ne) { ans += '-'; }
		reverse(ans.begin(), ans.end());

		return ans;
	}
};

int main() {
	int n;
	while (cin >> n) {
		Solution sol;
		cout << sol.convertTo7(n) << endl;
	}

	return 0;
}
