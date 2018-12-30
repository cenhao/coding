class Solution(object):
    def combinationSum3(self, k, n):
        """
        :type k: int
        :type n: int
        :rtype: List[List[int]]
        """
        buf, ans = [], []
        used = [False] * 9

        def dfs(cnt, sta, sm):
            if cnt == k:
                if sm == n: ans.append([v for v in buf])
                return
            for i in xrange(sta, 9):
                if used[i]: continue
                used[i] = True
                nsm = sm + i + 1
                if nsm <= n:
                    buf.append(i+1)
                    dfs(cnt+1, i+1, nsm)
                    buf.pop()
                used[i] = False

        dfs(0, 0, 0)
        return ans
