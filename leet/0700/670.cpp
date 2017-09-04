#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int maximumSwap(int num) {
		char buff[16]; snprintf(buff, sizeof(buff), "%d", num);
		int len = strlen(buff);
		for (int i=0; i<len-1; ++i) {
			int mx = buff[i]-'0', pos = -1;
			for (int j=i+1; j<len; ++j) {
				if (buff[j]-'0' >= mx && buff[j]-'0' != buff[i]-'0') {
					mx = buff[j]-'0';
					pos = j;
				}
			}

			if (pos > i) {
				swap(buff[i], buff[pos]);
				break;
			}
		}

		int ret; sscanf(buff, "%d", &ret);
		return ret;
	}
};

int main() {
	int n; cin >> n;
	Solution sol;
	cout << sol.maximumSwap(n) << endl;
	return 0;
}
