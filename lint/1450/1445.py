class Solution:
    """
    @param s: The string s
    @param t: The string t
    @return: Return if can get the string t
    """
    def canGetString(self, s, t):
        cnt = 0
        for c in s:
            if cnt >= len(t): break
            if c == t[cnt]: cnt += 1

        return cnt == len(t)
