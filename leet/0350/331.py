class Solution:
    def isValidSerialization(self, preorder):
        """
        :type preorder: str
        :rtype: bool
        """
        nodes = preorder.split(',')

        def traverse(cur):
            if cur < len(nodes) and nodes[cur] != '#':
                cur = traverse(cur+1)
                cur = traverse(cur+1)
            return cur

        return traverse(0) == len(nodes) - 1
