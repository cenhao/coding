/* This is a interesting problem.
 * Given the size of the data, it can be solved by a brute force algorithm like this:
 *
 * dfs(sum, last, mul)
 *   if sum == n
 *     if mul MOD m == 0
 *       return 1
 *     else
 *       return 0
 *   ans = 0
 *   for i: (last+1) to (n-sum)
 *     ans += dfs(sum+i, i, mul*i)
 *   return ans
 *
 * However, there's a property about GCD.
 * Given gcd(mul, m) = k, let's say mul = p*k, m = q*k,
 * and then we have:
 *   gcd(p, k) = 1
 * given an l, gcd(mul*l, m) = gcd(p*k*l, q*k) = k*gcd(p*l, q) >= k
 * and gcd(mul*l, m) = gcd(p*k*l, q*k) = gcd(k*l, q*k)
 *
 * so now we have three properties:
 * 1. gcd(mul*l, m) >= gcd(mul, m)
 * 2. gcd(mul*l, m) = gcd(gcd(mul, m)*l, m)
 * 3. gcd(mul, m) <= m
 *
 * now we can write the solution as following with DP
 */
#include <stdio.h>
#include <string.h>

#define MAXN 100
#define MAXM 50
#define MOD 1000000007

int dp[MAXN+1][MAXN+1][MAXM+1];

int n, m;

int gcd(int a, int b) {
	int tmp;
	while (b != 0) {
		tmp = b;
		b = a % b;
		a = tmp;
	}

	return a;
}

int dfs(int sum, int last, int gcdv) {
	if (dp[sum][last][gcdv] != -1) {
		return dp[sum][last][gcdv];
	}

	if (sum == n) {
		if (gcdv == m) {
			dp[sum][last][gcdv] = 1;
		} else {
			dp[sum][last][gcdv] = 0;
		}
	} else {
		dp[sum][last][gcdv] = 0;
		for (int i=last+1, end=n-sum; i<=end; ++i) {
			dp[sum][last][gcdv] += dfs(sum+i, i, gcd(gcdv*i, m)) % MOD;
			dp[sum][last][gcdv] %= MOD;
		}
	}

	return dp[sum][last][gcdv];
}

int main() {
	scanf("%d %d", &n, &m);
	memset(dp, -1, sizeof(dp));
	printf("%d\n", dfs(0, 0, 1));
	return 0;
}
