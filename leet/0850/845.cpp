class Solution {
public:
	int longestMountain(vector<int>& a) {
		if (a.size() < 3) { return 0; }
		int ans = 0;
		for (int i=1, pos=0, state=0; i<a.size(); ++i) {
			if (a[i] == a[i-1]) {
				pos = i;
				state = 0;
			} else if (a[i] > a[i-1]) {
				if (state == 2) { pos = i-1; }
				state = 1;
			} else {
				if (state != 0) {
					if (i - pos + 1 >= 3) { ans = max(ans, i-pos+1); }
					state = 2;
				} else {
					pos = i;
				}
			}
		}

		return ans;
	}
};
