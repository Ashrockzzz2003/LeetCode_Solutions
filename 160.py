# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def getIntersectionNode(self, headA: ListNode, headB: ListNode) -> Optional[ListNode]:
        if headA == headB:
            return headA
        
        # Equalize the two lists
        a = headA
        b = headB

        while a != b:
            if a:
                a = a.next
            else:
                a = headB
            if b:
                b = b.next
            else:
                b = headA
        
        return b

    
