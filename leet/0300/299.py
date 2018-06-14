class Solution:
    def getHint(self, secret, guess):
        """
        :type secret: str
        :type guess: str
        :rtype: str
        """
        n = len(secret)
        acnt, bcnt = 0, 0
        bmap = [0] * 10
        secret, guess = list(secret), list(guess)
        for i in range(n):
            if guess[i] == secret[i]:
                acnt += 1
                guess[i] = 'x'
            else:
                bmap[ord(secret[i])-ord('0')] += 1

        for i in range(n):
            if guess[i]!='x':
                idx = ord(guess[i]) - ord('0')
                if bmap[idx] > 0:
                    bcnt += 1
                    bmap[idx] -= 1

        return "{0}A{1}B".format(acnt, bcnt)
