class Solution:
    def find(self, x, f):
        if f[f[x]] != f[x]:
            f[x] = self.find(f[x], f)
        return f[x]

    def countComponents(self, n, edges):
        """
        :type n: int
        :type edges: List[List[int]]
        :rtype: int
        """
        f = [i for i in range(n)]
        for e in edges:
            p1, p2 = self.find(e[0], f), self.find(e[1], f)
            if p1 != p2: f[p2] = p1

        distinct = set()
        for i in range(n):
            distinct.add(self.find(i, f))

        return len(distinct)
