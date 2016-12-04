#include <algorithm>
#include <cstring>
#include <iostream>
#include <string>
using namespace std;

class Solution {
	public:
	int findSubstringInWraproundString(string p) {
		int mxl[26]; memset(mxl, 0, sizeof(mxl));

		string pp = '\n' + p + '*';
		int cnt = 0;
		for (int i=1, end=pp.length(); i<end; ++i) {
			if (pp[i] != pp[i-1]+1 && (pp[i] != 'a' || pp[i-1] != 'z')) {
				if (pp[i-1] <= 'z' && pp[i-1] >= 'a') {
					int start = i-cnt;
					int idx = pp[start] - 'a';
					for (int j=0, jend=min(cnt, 26); j<jend; ++j) {
						int iidx = (idx + j) % 26;
						mxl[iidx] = max(mxl[iidx], cnt-j);
					}
				}
				cnt = 0;
			}

			++cnt;
		}

		int ans = 0;
		for (int i=0; i<26; ++i) {
			ans += mxl[i];
		}

		return ans;
	}
};

int main() {
	string in;
	while (cin >> in) {
		Solution sol;
		cout << sol.findSubstringInWraproundString(in) << endl;
	}

	return 0;
}
