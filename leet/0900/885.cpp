class Solution {
public:
	int numRescueBoats(vector<int>& p, int limit) {
		sort(p.begin(), p.end());
		int l = 0, ans = 0;
		for (int i=p.size()-1; i>=l; --i) {
			if (i == l) {
				++ans;
			} else {
				if (p[i]+p[l] <= limit) { ++l; }
				++ans;
			}
		}
		return ans;
	}
};
