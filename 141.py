# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def hasCycle(self, head: Optional[ListNode]) -> bool:
        if not head:
            return False
        
        if not head.next:
            return False
        
        if head == head.next:
            return True

        currentNode = head
        while currentNode.next:
            currentNode.val = 100001

            if currentNode.next and currentNode.next.val == 100001:
                return True
            currentNode = currentNode.next
        
        return False
