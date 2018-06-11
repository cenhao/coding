class Solution:
    """
    @param n: the number of sectors
    @param m: the number of colors
    @return: The total number of plans.
    """
    def getCount(self, n, m):
        # Write your code here
        if n == 0: return 0
        same, diff = m, 0
        mod = 1000000007
        for i in range(1, n):
            ndiff = (diff * (m-2) + same * (m-1)) % mod
            nsame = diff % mod
            same, diff = nsame, ndiff
        return same if n == 1 else diff

sol = Solution()
print(sol.getCount(2, 3))
