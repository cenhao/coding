class Solution:
    def lengthOfLongestSubstringKDistinct(self, s, k):
        """
        :type s: str
        :type k: int
        :rtype: int
        """
        cnt = [0] * 128
        dcnt, l, mx = 0, 0, 0
        for r in range(len(s)):
            idx = ord(s[r])
            cnt[idx] += 1
            if cnt[idx] == 1: dcnt += 1
            while dcnt > k:
                lidx = ord(s[l])
                cnt[lidx] -= 1
                if cnt[lidx] == 0: dcnt -= 1
                l += 1

            mx = max(mx, r-l+1)

        return mx
