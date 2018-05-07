class Solution {
public:
	int hIndex(vector<int>& citations) {
		int sz = citations.size();
		int l = 0, r = sz;
		while (l <= r) {
			int h = (l + r) >> 1;
			int p = sz - h;
			
			if (p<sz && citations[p]<h) {
				r = h - 1;
			} else if (p>0 && citations[p-1]>h) {
				l = h + 1;
			} else {
				l = h + 1;
			}
		}

		return r;
	}
};
