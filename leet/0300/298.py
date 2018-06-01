# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def traverse(self, cur, pv, cnt):
        if cur == None:
            return cnt

        cnt = cnt + 1 if pv == cur.val-1 else 1
        left = self.traverse(cur.left, cur.val, cnt)
        right = self.traverse(cur.right, cur.val, cnt)
        return max(cnt, left, right)

    def longestConsecutive(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        return self.traverse(root, 0, 0)
