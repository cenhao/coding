#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
#define MOD 1000000007
	int64_t calc(int64_t a, int64_t b, int64_t c) {
		return (a * ((b * c / 2) % MOD)) % MOD;
	}
	int64_t calc1(int64_t a, int64_t b, int64_t c) {
		return (a * ((b * c) % MOD)) % MOD;
	}
	int tripletSumwithSingleDivisor(vector<int>& nums) {
		const int N = 50;
		vector<int> cnt(N+1, 0);
		for (auto n: nums) { ++cnt[n]; }
		int64_t ans = 0;
		for (int i=1; i<=N; ++i) {
			if (cnt[i] == 0) { continue; }
			if (cnt[i] > 1) {
				for (int j=i+1; j<=N; ++j) {
					if (cnt[j] == 0) { continue; }
					int tmp = i * 2 + j;
					if (tmp % i == 0) { continue; }
					if (tmp % j == 0) {
						ans = (ans + calc(cnt[j], cnt[i], cnt[i]-1)) % MOD;
					}
				}
			}
			for (int j=i+1; j<=N; ++j) {
				if (cnt[j] == 0) { continue; }
				if (cnt[j] > 1) {
					int tmp = i + j * 2;
					if ((tmp%j)!=0 && (tmp%i)==0) {
						ans = (ans + calc(cnt[i], cnt[j], cnt[j]-1)) % MOD;
					}
				}
				for (int k=j+1; k<=N; ++k) {
					if (cnt[k] == 0) { continue; }
					int tmp = i + j + k;
					int zcnt = 0;
					if ((tmp%i) == 0) ++zcnt;
					if ((tmp%j) == 0) ++zcnt;
					if ((tmp%k) == 0) ++zcnt;
					if (zcnt != 1) { continue; }
					ans = (ans+calc1(cnt[i], cnt[j], cnt[k])) % MOD;
				}
			}
		}

		ans = (ans * 6) % MOD;
		return ans;
	}
};

int main() {
	int n; cin >> n;
	vector<int> nums(n);
	for (int i=0; i<n; ++i) { cin >> nums[i]; }
	Solution sol;
	cout << sol.tripletSumwithSingleDivisor(nums) << endl;
	return 0;
}
