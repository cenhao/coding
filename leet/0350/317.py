from collections import deque

class Solution:
    def shortestDistance(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        if len(grid)==0 or len(grid[0])==0: return -1
        rsz, csz = len(grid), len(grid[0])
        vis = [[0 for j in range(csz)] for i in range(rsz)]
        step = [[0 for j in range(csz)] for i in range(rsz)]
        reach = [[0 for j in range(csz)] for i in range(rsz)]

        cnt, mov = 0, ((-1, 0), (0, -1), (1, 0), (0, 1))
        for i in range(rsz):
            for j in range(csz):
                if grid[i][j] != 1: continue
                cnt += 1
                q = deque([(i, j, 0)])
                vis[i][j] = cnt

                while len(q) > 0:
                    cur = q.popleft()
                    step[cur[0]][cur[1]] += cur[2]
                    reach[cur[0]][cur[1]] += 1
                    for m in mov:
                        nxt = (cur[0]+m[0], cur[1]+m[1], cur[2]+1)
                        if (nxt[0]<0 or nxt[0]>=rsz or nxt[1]<0
                                or nxt[1]>=csz or vis[nxt[0]][nxt[1]]==cnt
                                or grid[nxt[0]][nxt[1]]!=0):
                            continue
                        q.append(nxt)
                        vis[nxt[0]][nxt[1]] = cnt

        mn = -1
        for i in range(rsz):
            for j in range(csz):
                if grid[i][j]!=0 or reach[i][j]!=cnt: continue
                if mn==-1 or step[i][j]<mn: mn = step[i][j]

        return mn
