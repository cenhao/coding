#include <bits/stdc++.h>
using namespace std;
class Solution {
	struct Node {
		Node() {
			lnk[0] = lnk[1] = -1;
		}
		int lnk[2];
	};
	void insert(int v, vector<Node> &nodes) {
		int cur = 0;
		for (int i=31; i>=0; --i) {
			int idx = (v & (1<<i)) == 0 ? 0 : 1;
			if (nodes[cur].lnk[idx] == -1) {
				nodes[cur].lnk[idx] = nodes.size();
				nodes.emplace_back();
			}
			cur = nodes[cur].lnk[idx];
		}
	}
	int find(int v, vector<Node> &nodes) {
		int cur = 0, ret = 0, cnt = 0;
		for (int i=31; i>=0; --i) {
			int idx = (v & (1<<i))==0 ? 1 : 0;
			if (nodes[cur].lnk[idx] != -1) {
				cnt += idx;
			} else if (idx==1 || cnt>0) {
				idx ^= 1;
			}
			if (nodes[cur].lnk[idx] == -1) { return 0; }
			cur = nodes[cur].lnk[idx];
			ret |= idx << i;
		}
		return ret;
	}
public:
    /**
     * @param nums: the array
     * @return: the max xor sum of the subarray in a given array
     */
    int maxXorSubarray(vector<int> &nums) {
		vector<Node> nodes(1);
		int xsm = 0, mx = 0;
		for (auto n: nums) {
			xsm ^= n;
			int v = find(xsm, nodes);
			mx = max(mx, xsm ^ v);
			insert(xsm, nodes);
		}
		return mx;
    }
};

int main() {
	int n; cin >> n;
	vector<int> a(n);
	for (int i=0; i<n; ++i) { cin >> a[i]; }
	Solution sol;
	cout << sol.maxXorSubarray(a) << endl;
	return 0;
}
