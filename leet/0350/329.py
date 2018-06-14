class Solution:
    def longestIncreasingPath(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: int
        """
        if len(matrix)==0 or len(matrix[0])==0: return 0
        mov = [(-1, 0), (0, -1), (1, 0), (0, 1)]
        rsz, csz = len(matrix), len(matrix[0])

        def dfs(x, y):
            if dp[x][y] != -1: return dp[x][y]
            mx = 0
            for i in range(len(mov)):
                xx, yy = x + mov[i][0], y + mov[i][1]
                if (xx<0 or xx>=rsz or yy<0 or yy>=csz or matrix[xx][yy]<=matrix[x][y]):
                    continue
                mx = max(mx, dfs(xx, yy))
            dp[x][y] = 1 + mx
            return dp[x][y]

        dp = [[-1 for j in range(csz)] for i in range(rsz)]
        mx = 0
        for i in range(rsz):
            for j in range(csz):
                if dp[i][j] != -1: continue
                mx = max(mx, dfs(i, j))

        return mx
