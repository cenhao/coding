#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int subarrayBitwiseORs(vector<int>& a) {
		unordered_set<int> hs;
		vector<int> last(32, -1), pos(32);
		for (int i=0; i<a.size(); ++i) {
			hs.insert(a[i]);
			int cnt = 0;
			for (int j=0; j<30; ++j) {
				// if a bit is 1, the value won't change
				// only when it's 0 and it sees the first previous bit 1 a new number will
				// be generated
				if ((a[i] & (1<<j)) == 0) {
					if (last[j] >= 0)  { pos[cnt++] = last[j]; }
				} else {
					last[j] = i;
				}
			}
			sort(pos.begin(), pos.begin()+cnt);
			for (int j=cnt-1, tmp=a[i]; j>=0; --j) {
				tmp |= a[pos[j]];
				hs.insert(tmp);
			}
		}

		return hs.size();
	}
};

int main() {
	int n; cin >> n;
	vector<int> a(n); for (int i=0; i<n; ++i) { cin >> a[i]; }
	Solution sol;
	cout << sol.subarrayBitwiseORs(a) << endl;
	return 0;
}
