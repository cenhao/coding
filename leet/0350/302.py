from collections import deque

class Solution:
    def minArea(self, image, x, y):
        """
        :type image: List[List[str]]
        :type x: int
        :type y: int
        :rtype: int
        """
        if len(image)==0 or len(image[0])==0: return 0

        rsz, csz = len(image), len(image[0])
        mov = [(-1, 0), (0, -1), (1, 0), (0, 1)]
        image[x][y] = 0
        vmn, vmx = x, x
        hmn, hmx = y, y
        q = deque([(x, y)])

        while len(q) > 0:
            cur = q.popleft()
            for m in mov:
                nxt = (cur[0]+m[0], cur[1]+m[1])
                if (nxt[0]<0 or nxt[0]>=rsz or nxt[1]<0
                        or nxt[1]>=csz or image[nxt[0]][nxt[1]]=="0"):
                    continue
                image[nxt[0]][nxt[1]] = "0"
                q.append(nxt)
                vmn, vmx = min(vmn, nxt[0]), max(vmx, nxt[0])
                hmn, hmx = min(hmn, nxt[1]), max(hmx, nxt[1])

        return (vmx-vmn+1) * (hmx-hmn+1)
