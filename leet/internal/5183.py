from datetime import datetime

class Solution(object):
    def dayOfTheWeek(self, day, month, year):
        """
        :type day: int
        :type month: int
        :type year: int
        :rtype: str
        """
        d = datetime(year, month, day)
        return d.strftime("%A")
