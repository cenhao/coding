#include <algorithm>
#include <cstdio>
#include <vector>

class Solution {
	public:
		int findContentChildren(vector<int>& g, vector<int>& s) {
			sort(g.begin(), g.end());
			sort(s.begin(), s.end());

			int sn = 0;
			int ans = 0;
			for (int i=0, end=g.size(); i<end; ++i) {
				while (sn < s.size()) {
					if (s[sn++] >= g[i]) {
						++ans;
						break;
					}
				}
			}

			return ans;
		}
};
