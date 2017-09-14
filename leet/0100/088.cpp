class Solution {
public:
	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
		for (int i=m-1; i>=0; --i) { nums1[n+i] = nums1[i]; }
		int p1 = n, p2 = 0, p = 0;
		while (p1 < n+m && p2 < n) {
			if (nums1[p1] < nums2[p2]) {
				nums1[p++] = nums1[p1++];
			} else {
				nums1[p++] = nums2[p2++];
			}
		}

		while (p1 < n+m) { nums1[p++] = nums1[p1++]; }
		while (p2 < n) { nums1[p++] = nums2[p2++]; }
	}
};
