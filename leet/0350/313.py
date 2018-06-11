from collections import deque
class Solution:
    def nthSuperUglyNumber(self, n, primes):
        """
        :type n: int
        :type primes: List[int]
        :rtype: int
        """
        if n == 1: return 1
        pn = len(primes)
        qs = [deque([]) for i in range(pn)]
        for i, p in enumerate(primes):
            qs[i].append(p)

        ans = 1
        for i in range(1, n):
            tmp, pick = 0x7fffffff, -1
            for j, q in enumerate(qs):
                if q[0] <= tmp: tmp, pick = q[0], j
            ans = tmp
            for j in range(pick, pn):
                if tmp * primes[j] > 0x7fffffff: break
                qs[j].append(tmp * primes[j])

            qs[pick].popleft()

        return ans
