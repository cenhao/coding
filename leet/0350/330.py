class Solution:
    def minPatches(self, nums, n):
        """
        :type nums: List[int]
        :type n: int
        :rtype: int
        """
        sm, pos, cnt = 0, 0, 0
        while sm < n:
            if pos>=len(nums) or sm+1<nums[pos]:
                sm += sm + 1
                cnt += 1
            else:
                sm += nums[pos]
                pos += 1

        return cnt
