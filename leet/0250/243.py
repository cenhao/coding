class Solution(object):
    def shortestDistance(self, words, word1, word2):
        """
        :type words: List[str]
        :type word1: str
        :type word2: str
        :rtype: int
        """
        ans = len(words)
        p1, p2 = -ans, -ans

        for i, w in enumerate(words):
            if w == word1:
                p1 = i
            elif w == word2:
                p2 = i

            if p1 >=0 and p2 >= 0:
                ans = min(ans, abs(p1-p2))

        return ans
