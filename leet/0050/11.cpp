#include <stdio.h>
#include <vector>
using namespace std;

class Solution {
	public:
		int maxArea(vector<int>& height) {
			int l = 0, r = height.size() - 1;
			int mx = 0, tmp;
			while (l < r) {
				if (height[l] < height[r]) {
					tmp = height[l] * (r - l);
					++l;
				} else {
					tmp = height[r] * (r - l);
					--r;
				}
				mx = (tmp > mx) ? tmp : mx;
			}

			return mx;
		}
};

int main() {
	int n;
	while (EOF != scanf("%d", &n)) {
		vector<int> v;
		int a;
		for (int i=0; i<n; ++i) {
			scanf("%d", &a); v.push_back(a);
		}

		Solution sol;
		printf("%d\n", sol.maxArea(v));
	}
}
