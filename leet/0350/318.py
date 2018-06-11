class Solution:
    def maxProduct(self, words):
        """
        :type words: List[str]
        :rtype: int
        """
        conv = []
        for w in words:
            bits = 0
            for c in w: bits |= (1 << (ord(c)-ord('a')))
            conv.append((bits, len(w)))

        ans = 0
        for i in range(len(conv)):
            for j in range(i+1, len(conv)):
                if ((conv[i][0]&conv[j][0]) == 0
                        and conv[i][1]*conv[j][1] > ans):
                    ans = conv[i][1] * conv[j][1]

        return ans
