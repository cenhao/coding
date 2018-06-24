class Solution:
    """
    @param J: the types of stones that are jewels
    @param S: representing the stones you have
    @return: how many of the stones you have are also jewels
    """
    def numJewelsInStones(self, J, S):
        hs, cnt = set(J), 0
        for s in S:
            if s in hs: cnt += 1
        return cnt
