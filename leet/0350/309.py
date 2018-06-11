class Solution:
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        if len(prices) == 0: return 0

        gain = [0] * len(prices)
        mx = -prices[0]
        if len(prices) >= 2:
            gain[1] = max(0, prices[1]-prices[0])
            mx = max(mx, -prices[1])

        for i in range(2, len(prices)):
            gain[i] = max(gain[i-1], prices[i]+mx)
            mx = max(mx, gain[i-2]-prices[i])

        return gain[len(prices)-1]
