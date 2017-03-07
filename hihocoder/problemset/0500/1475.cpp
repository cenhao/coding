/*
 * So the simple idea for this problem is define a `dp` array,
 * where dp[i] means for the first i elements, the way to split the
 * array in to sub arrays so that none of the sums of sub-arrays is 0.
 * And dp[0] = 1 because if there's no element, there's no sub-array.
 *
 * Hence we have:
 *
 * dp[0] = 1;
 * for (int i=0; i<n; ++i) {
 *     int sum = 0, cnt = 0;
 *     for (int j=0; j<=i; ++j) {
 *         sum += arr[i-j];
 *         if (sum == 0) { continue; }
 *         cnt += dp[i-j];
 *     }
 *
 *     dp[i+1] = cnt;
 * }
 *
 * Then the result is dp[n].
 *
 * However, this approach has complexity of O(n^2), and n in this problem is 10^5.
 * It will have to be optimized to solve this problem.
 *
 * So the answer for dp[i+1] is in fact sum(dp[0..i-1]) - sum(dp[k]), where sum(array[k..i]) == 0
 * If we have array `cnt`, where cnt[i] is sum(dp[0..x]), for all x that has sum(array[0..x]) == i.
 * Let's said cursum = sum(array[0..i-1]), seg = sum(array[0..x-1]), then
 * array[i] + cursum - seg = sum(array[x..i]), so only when seg == array[i]+cursum,
 * sum(array[x..i]) is 0.
 *
 * So if we have all = sum(cnt[..]), then we have all - cnt[seg], where all is sum(dp[0..i-1]),
 * and cnt[seg] is sum(dp[k]), then we have dp[i].
 */
#include <cstdio>
#include <cstring>
using namespace std;

#define MOD 1000000007
#define MAXN 100000
#define OFFSET 10000000
#define IDX(x) (x+OFFSET)

int cnt[OFFSET*2+1];

int main() {
	int n; scanf("%d", &n);
	int all = 1, cursum = 0;
	memset(cnt, 0, sizeof(cnt));
	cnt[IDX(0)] = 1;
	int ans = 1;
	for (int i=0; i<n; ++i) {
		int a; scanf("%d", &a);
		int seg = cursum + a;
		int val = cnt[IDX(seg)];
		val = (all-val+MOD) % MOD;
		all = (all + val) % MOD;
		cursum += a;
		cnt[IDX(cursum)] = (cnt[IDX(cursum)]+val) % MOD;
		ans = val;
	}

	printf("%d\n", ans);
	return 0;
}
