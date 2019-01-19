# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def depth(self, root, idx, order):
        if root is None: return 0
        if idx < 0: return 1
        nxt = root.left if (order & (1 << idx)) == 0 else root.right
        return self.depth(nxt, idx - 1, order) + 1

    def countNodes(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        d = self.depth(root, 32, 0)
        if d <= 1: return d

        l, r = 0, (1 << (d - 1)) - 1

        while l <= r:
            m = (l + r) // 2
            dd = self.depth(root, d-2, m)

            if dd >= d:
                l = m + 1
            else:
                r = m - 1

        cnt = (1 << d) - 1
        for i in xrange(d-2, -1, -1):
            if (r & (1 << i)) == 0:
                cnt -= 1 << i

        return cnt
