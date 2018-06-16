from collections import deque
class Solution:
    """
    @param grid: The gird
    @return: Return the steps you need at least
    """
    def getBestRoad(self, grid):
        rsz, csz = len(grid), len(grid[0])
        step = [[[-1, -1] for j in range(csz)] for i in range(rsz)]
        q = deque([(0, 0, grid[0][0])])
        step[0][0][grid[0][0]] = 0
        mov = [(-1, 0), (0, -1), (1, 0), (0, 1)]

        while len(q) > 0:
            cur = q.popleft()
            cs = step[cur[0]][cur[1]][cur[2]]+1
            for m in mov:
                x, y = cur[0] + m[0], cur[1] + m[1]
                if x<0 or x>=rsz or y<0 or y>=csz: continue
                if grid[x][y] == 1:
                    if cur[2] == 1: continue
                    if step[x][y][1]==-1 or cs<step[x][y][1]:
                        step[x][y][1] = cs
                        q.append((x, y, 1))
                else:
                    if step[x][y][cur[2]]==-1 or cs<step[x][y][cur[2]]:
                        step[x][y][cur[2]] = cs
                        q.append((x, y, cur[2]))

        ans = -1
        if step[rsz-1][csz-1][0] >= 0: ans = step[rsz-1][csz-1][0]
        if step[rsz-1][csz-1][1] >= 0 and (ans==-1 or step[rsz-1][csz-1][1]<ans): ans = step[rsz-1][csz-1][1]
        return ans


sol = Solution()
#print(sol.getBestRoad([[0,1],[1, 0]]))
#print(sol.getBestRoad([[0,1,0,0,0],[0,0,0,1,0],[1,1,1,1,1],[1,1,1,1,1],[1,1,1,0,0]]))
print(sol.getBestRoad([[0,1,0,0,0],[0,0,0,1,0],[1,1,0,1,0],[1,1,1,1,0]]))
