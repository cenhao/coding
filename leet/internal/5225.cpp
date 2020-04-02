#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int maxEqualFreq(vector<int>& nums) {
		unordered_map<int, int> ncnt, fcnt;
		
		int ans = 0;
		for (int i=0; i<nums.size(); ++i) {
			int f = ++ncnt[nums[i]];
			auto it = fcnt.find(f-1);
			if (it!=fcnt.end() && (--it->second)==0) {
				fcnt.erase(it);
			}
			++fcnt[f];

			if (fcnt.size()==1) {
				if (fcnt.begin()->second==1 || fcnt.begin()->first==1) { ans = i; }
			} else if (fcnt.size() == 2) {
				auto bit = fcnt.begin();
				auto nit = next(bit);
				if (bit->first > nit->first) { swap(bit, nit); }
				if ((bit->second==1&&bit->first==1) || (nit->second==1&&nit->first==1)) {
					ans = i;
				} else if (nit->first-bit->first==1 && nit->second == 1) {
					ans = i;
				}
			}
		}

		return ans + 1;
	}
};

int main() {
	int n; cin >> n;
	vector<int> in(n);
	for (int i=0; i<n; ++i) { cin >> in[i]; }
	Solution sol;
	cout << sol.maxEqualFreq(in) << endl;
	return 0;
}
