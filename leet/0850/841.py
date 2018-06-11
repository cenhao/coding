from collections import deque
class Solution:
    def canVisitAllRooms(self, rooms):
        """
        :type rooms: List[List[int]]
        :rtype: bool
        """
        n, q, cnt = len(rooms), deque([0]), 0
        vis = [False] * n
        vis[0] = True

        while len(q) > 0:
            cur = q.popleft()
            cnt += 1
            for k in rooms[cur]:
                if vis[k]: continue
                vis[k] = True
                q.append(k)

        return n == cnt
