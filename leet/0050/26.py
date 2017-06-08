class Solution(object):
    def removeDuplicates(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if 0 == len(nums):
            return 0

        cnt = 1
        for i in xrange(1, len(nums)):
            if nums[i] != nums[cnt-1]:
                nums[cnt] = nums[i]
                cnt += 1
        return cnt
