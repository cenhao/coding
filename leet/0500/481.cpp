#include <iostream>
#include <string>
using namespace std;

class Solution {
	public:
	int magicalString(int n) {
		string s = "122";

		int idx = 2;
		while (s.length() < n) {
			char add = s[s.length() - 1] == '1' ? '2' : '1';
			int cur = s[idx] - '0';
			if (cur == 1) {
				s += add;
			} else {
				s += add; s += add;
			}

			++idx;
		}

		int ans = 0;
		for (int i=0; i<n; ++i) {
			if (s[i] == '1') { ++ans; }
		}

		return ans;
	}
};

int main() {
	int n;

	while (cin >> n) {
		Solution sol;
		cout << sol.magicalString(n) << endl;
	}

	return 0;
}
