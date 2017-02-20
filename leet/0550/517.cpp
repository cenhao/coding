#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int findMinMoves(vector<int>& machines) {
		int sum = 0;
		for (int i=0, end=machines.size(); i<end; ++i) { sum += machines[i]; }
		if (sum % machines.size() != 0) { return -1; }

		int target = sum / machines.size();
		int offset = 0, mx = 0;
		for (int i=0, end=machines.size(); i<end; ++i) {
			offset += machines[i] - target;
			mx = max(mx, max(abs(offset), machines[i]-target));
		}

		return mx;
	}
};

int main() {
	int n; cin >> n;
	vector<int> v(n);
	for (int i=0; i<n; ++i) { cin >> v[i]; }
	Solution sol;
	cout << sol.findMinMoves(v) << endl;
	return 0;
}
