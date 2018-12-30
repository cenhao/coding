from Queue import Queue

class Solution(object):
    def canFinish(self, numCourses, prerequisites):
        """
        :type numCourses: int
        :type prerequisites: List[List[int]]
        :rtype: bool
        """
        q = Queue()
        cnt = [0] * numCourses
        nxt = [set() for i in xrange(numCourses)]

        for p in prerequisites:
            cnt[p[0]] += 1
            nxt[p[1]].add(p[0])

        for i in xrange(numCourses):
            if cnt[i] == 0:
                q.put(i)

        while not q.empty():
            cur = q.get()
            numCourses -= 1
            for n in nxt[cur]:
                cnt[n] -= 1
                if cnt[n] == 0:
                    q.put(n)

        return numCourses == 0
