# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        currentNode = root
        while True:
            if currentNode.val > p.val and currentNode.val > q.val:
                currentNode = currentNode.left
            elif currentNode.val < p.val and currentNode.val < q.val:
                currentNode = currentNode.right
            else:
                return currentNode
