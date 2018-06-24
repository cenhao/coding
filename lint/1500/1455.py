class Solution:
    """
    @param a: The array.
    @return: The number which has odd number of times or -1.
    """
    def isValid(self, a):
        hm = {}
        for v in a:
            if v not in hm: hm[v] = 0
            hm[v] += 1

        ans, cnt = -1, 0
        for k, v in hm.items():
            if v & 1:
                cnt += 1
                ans = k

        return -1 if cnt != 1 else ans
