class Solution(object):
    def diffWaysToCompute(self, input):
        """
        :type input: str
        :rtype: List[int]
        """
        nums = []
        op = []
        v = 0
        for c in input:
            if c > '9' or c < '0':
                nums.append(v)
                v = 0
                op.append(c)
            else:
                v = v * 10 + ord(c) - ord('0')

        nums.append(v)

        dp = [[[] for j in xrange(len(nums))] for i in xrange(len(nums))]

        def dfs(l, r):
            if (l == r):
                return [nums[l]]
            if (len(dp[l][r]) > 0):
                return dp[l][r]
            for m in xrange(l, r):
                la = dfs(l, m)
                ra = dfs(m+1, r)
                for le in la:
                    for re in ra:
                        v = 0
                        if op[m] == '+':
                            v = le + re
                        elif op[m] == '-':
                            v = le - re
                        else:
                            v = le * re
                        dp[l][r].append(v)

            return dp[l][r]

        return dfs(0, len(nums)-1)

sol = Solution()
print(sol.diffWaysToCompute("2*3-4*5"))
