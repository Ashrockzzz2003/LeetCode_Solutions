# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        a = l1
        b = l2

        A = []
        B = []

        while a:
            A.append(a.val)
            a = a.next
        
        while b:
            B.append(b.val)
            b = b.next
        
        A.reverse()
        B.reverse()

        c = list(str(int("".join(str(x) for x in A)) + int("".join(str(x) for x in B))))

        head = l3 = ListNode(c.pop())

        c.reverse()

        for i in c:
            l3.next = ListNode(i)
            l3 = l3.next
        
        return head
