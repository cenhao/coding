class Solution:
    def countRangeSum(self, nums, lower, upper):
        """
        :type nums: List[int]
        :type lower: int
        :type upper: int
        :rtype: int
        """
        sz = len(nums)
        sm = [0] * (sz+1)
        tmp = [0] * (sz+1)
        for i, n in enumerate(nums): sm[i+1] = sm[i]+n

        def merge_sort(l, r):
            if l > r: return 0
            if l == r: return 1 if sm[l]>=lower and sm[l]<=upper else 0
            mid = (l + r) // 2
            cnt = merge_sort(l, mid) + merge_sort(mid+1, r)
            hidx, lidx = mid+1, mid+1
            for i in range(l, mid+1):
                while lidx<=r and sm[lidx]-sm[i]<lower: lidx += 1
                while hidx<=r and sm[hidx]-sm[i]<=upper: hidx += 1
                cnt += hidx - lidx

            lidx, ridx, idx = l, mid+1, l
            while lidx<=mid and ridx<=r:
                if sm[lidx] < sm[ridx]:
                    tmp[idx] = sm[lidx]
                    lidx += 1
                else:
                    tmp[idx] = sm[ridx]
                    ridx += 1
                idx += 1

            while lidx <= mid:
                tmp[idx] = sm[lidx]
                lidx, idx = lidx + 1, idx + 1

            while ridx <= r:
                tmp[idx] = sm[ridx]
                ridx, idx = ridx + 1, idx + 1

            for i in range(l, r+1): sm[i] = tmp[i]
            return cnt

        return merge_sort(1, sz)

sol = Solution()
print(sol.countRangeSum([-2, 5, -1], -2, 2))
