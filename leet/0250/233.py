class Solution(object):

    def __init__(self):
        self.dp = [[0 for j in xrange(10)] for i in xrange(11)]
        for i in xrange(1, 11):
            self.dp[i][0] = self.dp[i-1][9] + self.dp[i-1][0]
            self.dp[i][1] = self.dp[i][0] + 1
            self.dp[i][2] = self.dp[i][1] + self.dp[i][0] + (10 ** (i-1)) - 1 

            for j in xrange(3, 10):
                self.dp[i][j] = self.dp[i][j-1] + self.dp[i][0]

    def dfs(self, v):
        l = len(v)
        if (l == 0): return 0
        idx = ord(v[0]) - ord('0')
        ret = self.dfs(v[1:]) + (self.dp[l][idx] if idx != 0 else 0)
        ret += int(v[1:]) if idx == 1 and l > 1 else 0
        return ret

    def countDigitOne(self, n):
        """
        :type n: int
        :rtype: int
        """
        if (n < 0): n = 0
        return self.dfs(str(n))

sol = Solution()
print(sol.countDigitOne(100))
