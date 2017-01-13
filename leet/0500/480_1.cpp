#include <cstdio>
#include <functional>
#include <iostream>
#include <unordered_map>
#include <queue>
#include <vector>
using namespace std;

class Solution {
	public:
	priority_queue<int> mxheap;
	priority_queue<int, vector<int>, greater<int>> mnheap;
	unordered_map<int, int> extra;
	vector<double> ans;
	vector<double> medianSlidingWindow(vector<int>& nums, int k) {
		for (int i=1; i<k; ++i) { mxheap.push(nums[i-1]); }
		for (int i=(k-1)/2; i>0; --i) {
			mnheap.push(mxheap.top());
			mxheap.pop();
		}

		int mxextra = 0, mnextra = 0;
		for (int i=k-1; i<nums.size(); ++i) {
			if (!mnheap.empty() && nums[i] > mnheap.top()) {
				mnheap.push(nums[i]);
			} else {
				mxheap.push(nums[i]);
			}

			unordered_map<int, int>::iterator it;
			while (mxheap.size()-mxextra < mnheap.size()-mnextra) {
				mxheap.push(mnheap.top());
				mnheap.pop();
				while (mnextra > 0 && (it=extra.find(mnheap.top()))!=extra.end()) {
					--mnextra; mnheap.pop();
					if (--it->second == 0) { extra.erase(it); }
				}
			}
			while (mxheap.size()-mxextra > mnheap.size()-mnextra+1) {
				mnheap.push(mxheap.top());
				mxheap.pop();
				while (mxextra > 0 && (it=extra.find(mxheap.top()))!=extra.end()) {
					--mxextra; mxheap.pop();
					if (--it->second == 0) { extra.erase(it); }
				}
			}

			if (k & 1) {
				ans.push_back(mxheap.top());
			} else {
				ans.push_back(((double)mxheap.top()+mnheap.top()) / 2.0);
			}

			int toremove = nums[i-k+1];
			if (toremove <= mxheap.top()) {
				if (toremove == mxheap.top()) {
					mxheap.pop();
				} else {
					++mxextra;
					++extra[toremove];
				}
			} else if (toremove >= mnheap.top()) {
				if (toremove == mnheap.top()) {
					mnheap.pop();
				} else {
					++mnextra;
					++extra[toremove];
				}
			}

			while (mxextra > 0 && (it=extra.find(mxheap.top()))!=extra.end()) {
				mxheap.pop(); --mxextra;
				if (--it->second == 0) { extra.erase(it); }
			}
			while (mnextra > 0 && (it=extra.find(mnheap.top()))!=extra.end()) {
				mnheap.pop(); --mnextra;
				if (--it->second == 0) { extra.erase(it); }
			}
		}

		return ans;
	}
};

int main() {
	int n, k;
	while (cin >> n >> k) {
		vector<int> nums(n);
		for (int i=0; i<n; ++i) { cin >> nums[i]; }
		Solution sol;
		vector<double> ans = move(sol.medianSlidingWindow(nums, k));
		for (int i=0, end=ans.size(); i<end; ++i) {
			cout << ans[i] << endl;
		}
		
		cout << endl;
	}

	return 0;
}
