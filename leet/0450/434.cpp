#include <iostream>
#include <string>
using namespace std;

class Solution {
	public:
		int countSegments(string s) {
			int cnt = 0;
			bool ps = true;
			for (int i=0, end=s.length(); i<end; ++i) {
				if (s[i] != ' ') {
					if (ps) {
						++cnt;
					}
					ps = false;
				} else {
					ps = true;
				}
			}

			return cnt;
		}
};

int main() {
	string in;
	while (cin >> in) {
		Solution sol;
		cout << sol.countSegments(in) << endl;
	};
	return 0;
}
