#include <stdio.h>
#include <vector>
using namespace std;

class Solution {
	public:
		double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
			int target[2] = {(nums1.size() + nums2.size() + 1) / 2,
				(nums1.size() + nums2.size()) / 2 + 1};

			int sum = 0;
			for (int i=0; i<2; ++i) {
				int l1 = 0, r1 = nums1.size() - 1;
				int l2, r2;

				while (l1 <= r1) {
					int m1 = (l1 + r1) / 2;
					l2 = 0, r2 = nums2.size() - 1;

					while (l2 <= r2) {
						int m2 = (l2 + r2) / 2;
						if (nums2[m2] <= nums1[m1]) {
							l2 = m2 + 1;
						} else {
							r2 = m2 - 1;
						}
					}

					if (m1+1 + r2+1 <= target[i]) {
						l1 = m1 + 1;
					} else {
						r1 = m1 - 1;
					}
				}

				int idx1 = r1, idx2 = target[i] - r1 - 2;
				if (idx1 < 0) {
					sum += nums2[idx2];
				} else if (idx2 < 0) {
					sum += nums1[idx1];
				} else {
					sum += (nums1[idx1] > nums2[idx2]) ? nums1[idx1] : nums2[idx2];
				}
			}

			return sum / 2.0;
		}
};


int main() {
	int n1;
	vector<int> v1;
	scanf("%d", &n1);
	for (int i=0; i<n1; ++i) {
		int v; scanf("%d", &v);
		v1.push_back(v);
	}

	int n2;
	vector<int> v2;
	scanf("%d", &n2);
	for (int i=0; i<n2; ++i) {
		int v; scanf("%d", &v);
		v2.push_back(v);
	}

	Solution s;
	printf("%lf\n", s.findMedianSortedArrays(v1, v2));
	return 0;
}
