#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
	public:
		struct ValAndCnt {
			int val;
			int cnt;
			bool operator <(const ValAndCnt &vc) const {
				return val < vc.val;
			}
		};

		int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
			vector<int> CD(C.size() * D.size());
			for (int i=0, end=C.size(); i<end; ++i) {
				for (int j=0, endj=D.size(); j<endj; ++j) {
					CD[i*end+j] = C[i]+D[j];
				}
			}

			sort(A.begin(), A.end());
			sort(B.begin(), B.end());
			sort(CD.begin(), CD.end());

			vector<ValAndCnt> a, b, cd;
			for (int i=0, end=A.size(); i<end; ++i) {
				if (a.size() == 0 || a[a.size() - 1].val != A[i]) {
					ValAndCnt vc = { A[i], 1 };
					a.push_back(vc);
				} else {
					++a[a.size()-1].cnt;
				}
			}
			for (int i=0, end=B.size(); i<end; ++i) {
				if (b.size() == 0 || b[b.size() - 1].val != B[i]) {
					ValAndCnt vc = { B[i], 1 };
					b.push_back(vc);
				} else {
					++b[b.size()-1].cnt;
				}
			}
			for (int i=0, end=CD.size(); i<end; ++i) {
				if (cd.size() == 0 || cd[cd.size() - 1].val != CD[i]) {
					ValAndCnt vc = { CD[i], 1 };
					cd.push_back(vc);
				} else {
					++cd[cd.size()-1].cnt;
				}
			}

			int ans = 0;
			for (int i=0, end=a.size(); i<end; ++i) {
				for (int i1=0, end1=b.size(); i1<end1; ++i1) {
					int target = -(a[i].val+b[i1].val);
					ValAndCnt vtarget = { target, 0 };
					auto it = lower_bound(cd.begin(), cd.end(), vtarget);
					if (it != cd.end() && it->val == target) {
						ans += a[i].cnt * b[i1].cnt * it->cnt;
					}
				}
			}

			return ans;
		}
};

int main() {
	int n; cin >> n;
	vector<int> a(n), b(n), c(n), d(n);
	for (int i=0; i<n; ++i) { cin >> a[i]; }
	for (int i=0; i<n; ++i) { cin >> b[i]; }
	for (int i=0; i<n; ++i) { cin >> c[i]; }
	for (int i=0; i<n; ++i) { cin >> d[i]; }
	Solution sol;
	cout << sol.fourSumCount(a, b, c, d) << endl;
}
