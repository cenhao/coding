class Solution(object):
    def solve(self, v, subv, mul):
        if v < subv:
            return v, 0
        r, sm = self.solve(v, subv+subv, mul+mul)
        if r >= subv:
            r -= subv
            sm += mul

        return r, sm

    def divide(self, dividend, divisor):
        """
        :type dividend: int
        :type divisor: int
        :rtype: int
        """
        if divisor == 0:
            return -1
        r, sm = self.solve(abs(dividend), abs(divisor), 1)
        if (dividend < 0 and divisor > 0) or (dividend > 0 and divisor < 0):
            sm = -sm
        return sm
