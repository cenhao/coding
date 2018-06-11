class Solution:
    def countSmaller(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        tmp = [[v, i, 0] for i, v in enumerate(nums)]
        n = len(nums)
        rng = 1
        while rng < n:
            buf = [None for i in range(n)]
            for i in range(0, n, rng * 2):
                ls, le = i, min(i+rng, n)
                rs, re = min(i+rng, n), min(i+rng+rng, n)
                cnt, pos = 0, ls
                
                while ls < le and rs < re:
                    if tmp[ls][0] > tmp[rs][0]:
                        buf[pos] = tmp[rs]
                        cnt, rs, pos = cnt+1, rs+1, pos+1
                    else:
                        buf[pos] = tmp[ls]
                        buf[pos][2] += cnt
                        ls, pos = ls+1, pos+1

                while ls < le:
                    buf[pos] = tmp[ls]
                    buf[pos][2] += cnt
                    ls, pos = ls+1, pos+1
                while rs < re:
                    buf[pos] = tmp[rs]
                    rs, pos = rs+1, pos+1
            tmp = buf
            rng *= 2

        ans = [0] * n
        for v in tmp: ans[v[1]] = v[2]
        return ans
