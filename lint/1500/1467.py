class Solution:
    """
    @param arr: The release order
    @param n: The cooldown
    @return: Return the time
    """
    def askForCoolingTime(self, arr, n):
        sz, occ, ans= len(arr), {}, 0
        if sz == 0: return 0
        for i in range(sz):
            idx = arr[i] - 1
            if idx in occ: ans = max(ans, occ[idx]+n)
            ans += 1
            occ[idx] = ans

        return ans
