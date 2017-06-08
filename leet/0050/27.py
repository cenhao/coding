class Solution(object):
    def removeElement(self, nums, val):
        """
        :type nums: List[int]
        :type val: int
        :rtype: int
        """
        cnt = 0
        for i in xrange(len(nums)):
            if nums[i] != val:
                nums[cnt] = nums[i]
                cnt += 1

        return cnt
