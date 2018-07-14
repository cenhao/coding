class Solution:
    """
    @param arr: The 2-dimension array
    @return: Return the column the leftmost one is located
    """
    def getColumn(self, arr):
        mn = -1
        for a in arr:
            l, r = 0, len(a)-1
            while l <= r:
                m = (l + r) >> 1
                if a[m] == 0:
                    l = m + 1
                else:
                    r = m - 1

            if mn==-1 or l<mn: mn = l

        return mn
