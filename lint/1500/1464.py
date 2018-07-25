class Solution:
    """
    @param n: The integer n
    @param k: The integer k
    @return: Return the combination
    """
    def getCombination(self, n, k):
        comb = [[-1 for j in range(n//2 + 1)] for i in range(n+1)]
        def get_comb(n, m):
            if comb[n][m] != -1: return comb[n][m]
            if m == 0 or n == m:
                comb[n][m] = 1
            else:
                comb[n][m] = get_comb(n-1, m-1) + get_comb(n-1, m)
            return comb[n][m]

        ans = [-1] * (n//2)
        pos = -1
        for i in range(n//2):
            cnt = 0
            for j in range(pos+1, n):
                v = get_comb(n-j-1, n//2-i-1)
                if k-v <= 0:
                    pos = j
                    break
                k -= v

            ans[i] = pos+1

        return ans


sol = Solution()
print(sol.getCombination(18, 3014))
