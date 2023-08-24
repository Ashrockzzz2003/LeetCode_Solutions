# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def minDepth(self, root: Optional[TreeNode]) -> int:
        if root is None:
            return 0
        
        if root.left == None and root.right == None:
            return 1

        level = 1
        queue = [root, None]

        while len(queue) > 0:
            currentNode = queue.pop(0)

            if currentNode == None:
                level += 1
                if len(queue) > 0:
                    queue.append(None)
            else:
                if currentNode.left == None and currentNode.right == None:
                    return level
                if currentNode.left != None:
                    queue.append(currentNode.left)
                if currentNode.right != None:
                    queue.append(currentNode.right)
            

