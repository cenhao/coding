class Solution(object):
    def findDuplicate(self, paths):
        """
        :type paths: List[str]
        :rtype: List[List[str]]
        """
        hm = {}
        for path in paths:
            items = path.split()
            l = len(items)
            if l == 1:
                continue
            for i in xrange(1, l):
                item = items[i]
                pair = item.split('(')
                if not pair[1] in hm:
                    hm[pair[1]] = []
                hm[pair[1]].append(items[0] + '/' + pair[0])

        ans = []
        for lst in hm.values():
            if len(lst) > 1:
                ans.append(lst)
        return ans
