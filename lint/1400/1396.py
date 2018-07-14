class Solution:
    """
    @param sets: Initial set list
    @return: The final number of sets
    """
    def setUnion(self, sets):
        n = len(sets)
        f = [i for i in range(n)]

        def find(x):
            f[x] = f[x] if f[f[x]] == f[x] else find(f[x])
            return f[x]

        for i in range(n):
            for j in range(i+1, n):
                si, sj = set(sets[i]), set(sets[j])
                if len(si.intersection(sj)) > 0:
                    pi, pj = find(i), find(j)
                    f[pj] = pi;

        cnt = 0
        for i in range(n):
            if i == find(i): cnt += 1

        return cnt
