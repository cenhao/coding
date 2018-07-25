class Solution:
    """
    @param words1: the words in paper1
    @param words2: the words in paper2
    @param pairs: the similar words pair
    @return: the similarity of the two papers
    """
    def getSimilarity(self, words1, words2, pairs):
        hm, cnt = {}, 0
        for ws in (words1, words2, *pairs):
            for w in ws:
                if w not in hm:
                    hm[w] = cnt
                    cnt += 1

        f = [i for i in range(cnt)]
        def find(x):
            if f[x] != f[f[x]]:
                f[x] = find(f[x])
            return f[x]

        for p in pairs:
            f1, f2 = find(hm[p[0]]), find(hm[p[1]])
            f[f2] = f1;

        d1 = [find(hm[w]) for w in words1]
        d2 = [find(hm[w]) for w in words2]

        dp = [[0] * (len(d1)+1) for i in range(2)]

        mx = 0
        for i in range(len(d2)):
            cur, pre = (i+1) & 1, (i+2) & 1
            for j in range(len(d1)):
                if d2[i] == d1[j]:
                    dp[cur][j+1] = 1 + dp[pre][j]
                else:
                    dp[cur][j+1] = max(dp[cur][j], dp[pre][j+1])
                mx = max(dp[cur][j+1], mx)

        return mx * 2 / (len(d1)+len(d2))
