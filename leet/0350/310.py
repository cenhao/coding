from collections import defaultdict
from sys import maxsize
class Solution:
    def dfs(self, cur, par, adj, h):
        for c in adj[cur]:
            if c == par: continue
            h[cur] = max(h[cur], self.dfs(c, cur, adj, h)+1)
        return h[cur]

    def dfs1(self, cur, par, adj, h, ph, ans, mn):
        mx, smx = ph, ph
        mxp, smxp = par, par
        for c in adj[cur]:
            if c == par: continue
            if h[c] > mx:
                smx, smxp = mx, mxp
                mx, mxp = h[c], c
            elif h[c] > smx:
                smx, smxp = h[c], c

        if mx+1 < mn:
            ans.clear()
            ans.append(cur)
            mn = mx+1
        elif mx+1 == mn:
            ans.append(cur)

        for c in adj[cur]:
            if c == par: continue
            if c == mxp:
                self.dfs1(c, cur, adj, h, smx+1, ans, mn)
            else:
                self.dfs1(c, cur, adj, h, mx+1, ans, mn)

    def findMinHeightTrees(self, n, edges):
        """
        :type n: int
        :type edges: List[List[int]]
        :rtype: List[int]
        """
        adj = defaultdict(list)
        for e in edges:
            adj[e[0]].append(e[1])
            adj[e[1]].append(e[0])

        h, ans = [1] * n, []
        self.dfs(0, -1, adj, h)
        self.dfs1(0, -1, adj, h, 0, ans, maxsize)
        return ans


sol = Solution()
print(sol.findMinHeightTrees(4, [[1,0],[1,2],[1,3]]))
