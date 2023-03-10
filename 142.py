# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def detectCycle(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if head is None:
            return head
        
        if head.next == head:
            return head

        currentNode = head
        flag = True
        while flag and currentNode.next:
            currentNode.val = 100001
            if(currentNode.next and currentNode.next.val > 100000):
                flag = False
                break
            currentNode = currentNode.next
        
        if flag:
            return currentNode.next
        else:
            return currentNode.next
