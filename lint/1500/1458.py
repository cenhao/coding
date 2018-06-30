class Solution:
    """
    @param arr: The given matrix
    @return: Return the mininum sum
    """
    def minimumSubmatrix(self, arr):
        r, c = len(arr), len(arr[0])
        dp = [[0 for j in range(c)] for i in range(c)]

        mn, init = 0, False
        for i in range(r):
            for j in range(c):
                sm = 0
                for k in range(j, -1, -1):
                    sm += arr[i][k]
                    tmp = dp[k][j] + sm
                    dp[k][j] = min(0, tmp)

                    if not init or tmp<mn:
                        init = True
                        mn = tmp

        return mn

arr = [[-3,-2,-1],[-2,3,-2],[-1,3,-1]]
sol = Solution()
print(sol.minimumSubmatrix(arr))
