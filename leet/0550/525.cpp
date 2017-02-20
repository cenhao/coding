#include <algorithm>
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
	int findMaxLength(vector<int>& nums) {
		unordered_map<int, int> hashmap(nums.size());
		unordered_map<int, int>::iterator it;
		hashmap[0] = -1;
		int sum = 0, mx = 0;
		for (int i=0; i<nums.size(); ++i) {
			sum += nums[i] ? -1 : 1;
			it = hashmap.find(sum);
			if (it != hashmap.end()) {
				mx = max(mx, i - it->second);
			} else {
				hashmap[sum] = i;
			}
		}

		return mx;
	}
};

int main() {
	int n; cin >> n;
	vector<int> v(n);
	for (int i=0; i<n; ++i) {
		cin >> v[i];
	}

	Solution sol;
	cout << sol.findMaxLength(v) << endl;
	return 0;
}
