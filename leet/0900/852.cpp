class Solution {
public:
	int peakIndexInMountainArray(vector<int>& a) {
		int pos = -1, mx;
		for (int i=0; i<a.size(); ++i) {
			if (pos == -1 || a[i] > mx) {
				mx = a[i];
				pos = i;
			}
		}
		return pos;
	}
};
