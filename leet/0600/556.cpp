#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int nextGreaterElement(int n) {
		char buff[16], cal_buff[16];
		snprintf(buff, sizeof(buff), "%d", n);
		int len = strlen(buff);
		int ans = -1;

		for (int i=len-1; i>0; --i) {
			long long tmp = -1;
			for (int j=i-1; j>=0; --j) {
				if (buff[i] > buff[j]) {
					snprintf(cal_buff, sizeof(cal_buff), "%s", buff);
					swap(cal_buff[j], cal_buff[i]);
					sort(cal_buff+j+1, cal_buff+len);
					sscanf(cal_buff, "%lld", &tmp);
					break;
				}
			}

			if (tmp != -1) {
				if (tmp <= 0x7fffffff) {
					if (ans == -1 || tmp < ans) {
						ans = tmp;
					}
				}
			}
		}

		return ans;
	}
};

int main() {
	int n; cin >> n;
	Solution sol;
	cout << sol.nextGreaterElement(n) << endl;
	return 0;
}
