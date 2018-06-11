class Solution:
    """
    @param S: a String consists of a and b
    @return: the longest of the longest string that meets the condition
    """
    def getAns(self, S):
        # Write your code here
        cnt, ans = 0, 0
        hm = {0: -1}
        for i, c in enumerate(S):
            cnt += 1 if c == 'A' else -1
            if cnt in hm:
                ans = max(ans, i-hm[cnt])
            else:
                hm[cnt] = i
        return ans
