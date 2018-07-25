class Solution:
    """
    @param n: The number of gift box
    @param m: The number of goods
    @param k: The money you have
    @param val: The value of each item
    @param cost: The cost of each item
    @param belong: The item you need to buy before
    @return: Return the max value.
    """
    def getAns(self, n, m, k, val, cost, belong):
        boxes = [[] for i in range(n)]
        for i in range(m):
            boxes[belong[n+i]].append((cost[n+i], val[n+i]))

        dp = [-1] * (k+1)
        dp[0] = 0

        for i in range(n):
            sdp = [-1] * (k+1)
            for j in range(k-cost[i], -1, -1):
                if dp[j] >= 0: sdp[j+cost[i]] = dp[j] + val[i]
            for c, v in boxes[i]:
                for j in range(k-c, -1, -1):
                    if sdp[j]>=0 and sdp[j+c]<sdp[j]+v: sdp[j+c] = sdp[j] + v

            for j in range(k+1):
                dp[j] = max(dp[j], sdp[j])

        mx = -1
        for i in range(k+1):
            mx = max(dp[i], mx)

        return mx
