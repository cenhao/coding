class Solution:
    """
    @param n: The number of cards
    @param totalProfit: The totalProfit
    @param totalCost: The totalCost
    @param a: The profit of cards
    @param b: The cost of cards
    @return: Return the number of legal plan
    """
    def numOfPlan(self, n, totalProfit, totalCost, a, b):
        dp = [[0 for j in range(totalProfit+2)] for i in range(totalCost)]
        dp[0][0] = 1
        mod = 1000000007

        for k in range(n):
            for i in range(totalCost-1, -1, -1):
                iidx = i + b[k]
                if iidx >= totalCost: continue
                for j in range(totalProfit+1, -1, -1):
                    jidx = min(totalProfit+1, j + a[k])
                    dp[iidx][jidx] = (dp[iidx][jidx]+dp[i][j]) % mod

        ans = 0
        for i in range(totalCost):
            ans = (ans+dp[i][totalProfit+1]) % mod

        return ans

sol = Solution()
#print(sol.numOfPlan(3, 5, 10, [6, 7, 8], [2, 3, 5]))
print(sol.numOfPlan(54, 6, 19, [50,52,15,60,58,45,82,76,48,84,84,68,28,10,2,87,31,36,23,95,3,25,68,91,34,67,21,29,6,78,96,62,92,43,95,37,42,23,99,22,10,33,16,16,0,96,42,32,51,24,44,55,81,86], [0,2,0,0,0,2,1,2,2,1,2,1,2,0,0,0,1,2,1,0,2,1,0,2,0,0,0,2,0,1,1,0,0,1,1,2,1,2,0,2,2,1,2,1,1,1,2,0,1,2,2,1,1,1]))
