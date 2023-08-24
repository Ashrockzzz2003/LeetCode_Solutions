# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def height(self, root: Optional[TreeNode]):
        if root == None:
            return 0

        level = [root]
        height = 0
        while level:
            height += 1
            lev = []
            for node in level:
                for kid in (node.left, node.right):
                    if kid:
                        lev.append(kid)
                
                level = lev
        
        return height
        
    def isBalanced(self, root: Optional[TreeNode]) -> bool:
        if root == None:
            return True
        
        if root.left == None and root.right == None:
            return True
        
        if abs(self.height(root.left) - self.height(root.right)) > 1:
            return False
        
        return self.isBalanced(root.left) and self.isBalanced(root.right)