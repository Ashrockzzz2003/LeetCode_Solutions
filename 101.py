# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isSymmetric(self, node: Optional[TreeNode]) -> bool:
        def isSymmetricRec(left, right):
            if left == None and right == None:
                return True
            elif left == None or right == None:
                return False
            elif left.val == right.val:
                return isSymmetricRec(left.left, right.right) and isSymmetricRec(left.right, right.left)
            
            return False
        
        return isSymmetricRec(node, node)


