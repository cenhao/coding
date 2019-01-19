class Solution(object):
    def computeArea(self, x1, y1, x2, y2, x3, y3, x4, y4):
        """
        :type x1: int
        :type y1: int
        :type x2: int
        :type y2: int
        :type x3: int
        :type y3: int
        :type x4: int
        :type y4: int
        :rtype: int
        """
        sz1 = (x2-x1) * (y2-y1)
        sz2 = (x4-x3) * (y4-y3)
        xlb, ylb = max(x1, x3), max(y1, y3)
        xrt, yrt = min(x2, x4), min(y2, y4)
        sz3 = max(0, xrt-xlb) * max(0, yrt-ylb)
        return sz1 + sz2 - sz3
