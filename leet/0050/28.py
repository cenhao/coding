class Solution(object):
    def strStr(self, haystack, needle):
        """
        :type haystack: str
        :type needle: str
        :rtype: int
        """

        if haystack is None or needle is None or len(haystack) < len(needle):
            return -1

        for i in xrange(len(haystack)-len(needle)):
            found = True
            for j in xrange(len(needle)):
                if haystack[i+j] != needle[j]:
                    found = False
                    break

            if found:
                return i

        return 0 if len(haystack) == 0 and len(needle) == 0 else -1
