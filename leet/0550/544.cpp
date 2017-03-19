#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	string findContestMatch(int n) {
		string arr[n/2];
		char buff[16];
		for (int i=0; i<n/2; ++i) {
			snprintf(buff, sizeof(buff), "(%d,", i+1);
			arr[i] = buff;
			snprintf(buff, sizeof(buff), "%d)", n-i);
			arr[i] += buff;
		}

		int len = n / 2;
		while (len > 1) {
			for (int i=0; i<len/2; ++i) {
				arr[i] = "(" + move(arr[i]) + "," + move(arr[len-1-i]) + ")";
			}

			len /= 2;
		}

		return arr[0];
	}
};

int main() {
	int n; cin >> n;
	Solution sol;
	cout << sol.findContestMatch(n) << endl;
	return 0;
}
