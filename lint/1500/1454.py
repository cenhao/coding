import re

class Solution:
    """
    @param s: The string s
    @param excludeList: The excludeList
    @return: Return the most frequent words
    """
    def getWords(self, s, excludeList):
        hs, hm, mx = set([e.lower() for e in excludeList]), {}, 0
        for w in re.sub(r"[^a-zA-Z]", " ", s).split():
            w = w.lower()
            if w in hs: continue
            if w not in hm: hm[w] = 0
            hm[w] += 1
            mx = max(mx, hm[w])

        ans = []
        for k, v in hm.items():
            if v == mx: ans.append(k)

        return sorted(ans)
