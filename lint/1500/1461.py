from functools import cmp_to_key
class Solution:
    """
    @param meeting: The meetings
    @param pause: The pause time of meetings
    @param query: The query
    @return: Return the answer of each query
    """
    def getQuery(self, meeting, pause, query):
        def cmp(x, y):
            if x[0] != y[0]:
                return x[0] - y[0]
            return x[1]-y[1] if x[1]!=y[1] else x[2]-y[2]
        pause.sort(key=cmp_to_key(cmp))
        psz, lid, rng = len(pause), -1, [-1, -1]
        new_pause = []
        for i in range(psz):
            if pause[i][0]!=lid or pause[i][1]>rng[1]:
                if rng[0] >= 0: new_pause.append(rng)
                rng = [pause[i][1], pause[i][2]]
                lid = pause[i][0]
            else:
                rng[1] = max(rng[1], pause[i][2])
        if rng[0] >= 0: new_pause.append(rng)

        q = [(v, i) for i, v in enumerate(query)]
        q.sort(key=lambda t: t[0])
        cnt = {}
        for r in meeting:
            if r[1] not in cnt: cnt[r[1]] = [0, 0]
            cnt[r[1]][0] += 1
            if r[2] not in cnt: cnt[r[2]] = [0, 0]
            cnt[r[2]][1] -= 1

        for r in new_pause:
            if r[0] not in cnt: cnt[r[0]] = [0, 0]
            cnt[r[0]][0] -= 1
            if r[1] not in cnt: cnt[r[1]] = [0, 0]
            cnt[r[1]][1] += 1

        sm, pos, qsz = 0, 0, len(query)
        ans = [0] * qsz
        for key in sorted(cnt):
            while pos<qsz and q[pos][0]<key:
                ans[q[pos][1]] = sm
                pos += 1
            sm += cnt[key][0]
            while pos<qsz and q[pos][0]==key:
                ans[q[pos][1]] = sm
                pos += 1
            sm += cnt[key][1]

        while pos<qsz:
            ans[q[pos][1]] = sm
            pos += 1

        return ans

sol = Solution()
print(sol.getQuery([[1,1,10]], [[1,1,2],[1,9,10],[1,6,7],[1,1,4]], [1,5,8,10]))
print(sol.getQuery([[3,9,12],[6,8,12],[9,6,8],[12,7,11]], [[3,12,12],[6,12,12],[6,12,12],[9,8,8],[3,12,12],[6,11,12],[6,9,11]], [0,3,6]))
print(sol.getQuery([[1,1,5],[2,2,8],[3,1,4]], [[1,1,2],[1,1,4],[2,5,6],[2,7,7]], [1,2,3,4,5]))
