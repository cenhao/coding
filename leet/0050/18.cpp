#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

/*
class Solution {
	public:
		vector<vector<int> > fourSum(vector<int>& nums, int target) {
			sort(nums.begin(), nums.end());

			vector<vector<int> > result;
			for (int i=0, end=nums.size()-3; i<end; ++i) {
				if (i > 0 && nums[i] == nums[i-1]) { continue; }
				for (int i1=i+1, end1=end+1; i1<end1; ++i1) {
					if (i1>i+1 && nums[i1] == nums[i1-1]) { continue; }
					int left = target - nums[i] - nums[i1];
					int l = i1+1, r = end1+1;
					while (l < r) {
						int sum = nums[l] + nums[r];
						if (sum < left) {
							++l;
						} else if (sum > left) {
							--r;
						} else {
							if (!(l > i1+1 && nums[l] == nums[l-1]) &&
									!(r < end1+1 && nums[r] == nums[r+1])) {
								vector<int> four;
								four.push_back(nums[i]); four.push_back(nums[i1]);
								four.push_back(nums[l]); four.push_back(nums[r]);
								result.push_back(four);
							}
							++l; --r;
						}
					}
				}
			}

			return result;
		}
};
*/

class Solution {
	public:
		struct SumAndIndex {
			int sum;
			int idx1, idx2;
		};

		class FourSumHasher {
			public:
			size_t operator() (const vector<int> &v) const {
				return ((size_t) v[0]) +
					(((size_t) v[1])<<16) +
					(((size_t) v[2])<<32) +
					(((size_t) v[3])<<48);
			}
		};

		class FourSumEqualChecker {
			public:
			bool operator() (const vector<int> &v1, const vector<int> &v2) const {
				return (v1[0] == v2[0]) && (v1[1] == v2[1])
					&& (v1[2] == v2[2]) && (v1[3] == v2[3]);
			}
		};

		vector<vector<int> > fourSum(vector<int>& nums, int target) {
			vector<vector<int> > result;
			if (nums.size() < 4) { return result; }

			SumAndIndex sums[nums.size() * (nums.size()-1) / 2];
			int cnt = 0;
			for (int i=0, end=nums.size(); i<end; ++i) {
				for (int i1=i+1; i1<end; ++i1) {
					if (i == i1) { continue; }
					sums[cnt].sum = nums[i] + nums[i1];
					sums[cnt].idx1 = i; sums[cnt].idx2 = i1;
					++cnt;
				}
			}

			sort(sums, sums+cnt, [](const SumAndIndex &s1, const SumAndIndex &s2) {
				return s1.sum < s2.sum;
			});

			unordered_set<vector<int>, FourSumHasher, FourSumEqualChecker> sumset;
			int l=0, r=cnt-1;
			while (l < r) {
				int sum = sums[l].sum + sums[r].sum;
				if (sum < target) {
					++l;
				} else if (sum > target) {
					--r;
				} else {
					int ll = l;
					while (ll < r && sum == target) {
						unordered_set<int> hashset;
						hashset.insert(sums[ll].idx1);
						hashset.insert(sums[ll].idx2);
						hashset.insert(sums[r].idx1);
						hashset.insert(sums[r].idx2);
						if (hashset.size() == 4) {
							vector<int> v(4);
							v[0] = nums[sums[ll].idx1]; v[1] = nums[sums[ll].idx2];
							v[2] = nums[sums[r].idx1]; v[3] = nums[sums[r].idx2];
							sort(v.begin(), v.end());
							auto it = sumset.find(v);
							if (it == sumset.end()) {
								sumset.insert(move(v));
							}
						}
						++ll;
						sum = sums[ll].sum + sums[r].sum;
					}

					int rr = r-1;
					sum = sums[l].sum + sums[rr].sum;
					while (l < rr && sum == target) {
						unordered_set<int> hashset;
						hashset.insert(sums[l].idx1);
						hashset.insert(sums[l].idx2);
						hashset.insert(sums[rr].idx1);
						hashset.insert(sums[rr].idx2);
						if (hashset.size() == 4) {
							vector<int> v(4);
							v[0] = nums[sums[l].idx1]; v[1] = nums[sums[l].idx2];
							v[2] = nums[sums[rr].idx1]; v[3] = nums[sums[rr].idx2];
							sort(v.begin(), v.end());
							auto it = sumset.find(v);
							if (it == sumset.end()) {
								sumset.insert(move(v));
							}
						}
						--rr;
						sum = sums[l].sum + sums[rr].sum;
					}

					++l; --r;
				}
			}

			for (auto &e: sumset) { result.push_back(e); }
			return result;
		}
};

int main() {
	int n; cin >> n;
	vector<int> v(n);
	for (int i=0; i<n; ++i) {
		cin >> v[i];
	}

	Solution sol;
	auto res = sol.fourSum(v, 0);
	for (auto &e: res) {
		cout << e[0] << " " << e[1] << " " << e[2] << " " << e[3] << endl;
	}

	return 0;
}
