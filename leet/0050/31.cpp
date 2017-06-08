#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	void nextPermutation(vector<int>& nums) {
		int pos;
		for (pos=nums.size()-2; pos>=0; --pos) {
			if (nums[pos] < nums[pos+1]) { break; }
		}

		if (pos >= 0) {
			for (int i=nums.size()-1; i>pos; --i) {
				if (nums[i] > nums[pos]) {
					swap(nums[i], nums[pos]);
					break;
				}
			}
		}

		for (int i=pos+1, end=pos+(nums.size()-pos-1)/2; i<=end; ++i) {
			swap(nums[i], nums[nums.size()+pos-i]);
		}
	}
};

int main() {
	int n; cin >> n;
	vector<int> v(n);
	for (int i=0; i<n; ++i) { cin >> v[i]; }
	Solution sol;
	sol.nextPermutation(v);
	for (int i=0; i<n; ++i) { cout << v[i] << endl; }
	return 0;
}
