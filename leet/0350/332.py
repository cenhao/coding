class Solution:
    def findItinerary(self, tickets):
        """
        :type tickets: List[List[str]]
        :rtype: List[str]
        """
        adj = {}
        for t in tickets:
            if not t[0] in adj: adj[t[0]] = []
            adj[t[0]].append(t[1])

        for k, v in adj.items(): v.sort()
        n = len(tickets)
        ans = []

        def dfs(cur, cnt):
            ans.append(cur)
            if cnt == n: return True
            if cur in adj:
                for i in range(len(adj[cur])):
                    if adj[cur][i] == None: continue
                    tmp = adj[cur][i]
                    adj[cur][i] = None
                    if dfs(tmp, cnt+1): return True
                    adj[cur][i] = tmp
            ans.pop()
            return False

        dfs("JFK", 0)
        return ans
