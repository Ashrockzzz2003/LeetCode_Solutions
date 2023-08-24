# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def maxDepth(self, root: Optional[TreeNode]) -> int:
        if root is None:
            return 0
        
        height = 0
        level = [root]
        while level:
            height += 1
            lev = []
            for node in level:
                for kid in (node.left, node.right):
                    if kid:
                        lev.append(kid)
            level = lev
            
        return height