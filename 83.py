# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def deleteDuplicates(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if not head or not head.next:
            return head

        prevUniqueNode = head
        currNode = head

        # 1 1 1 2 2 3 3 4 5 5
        # pun = 5
        # cn = 5

        # 1 1 2 -> 1 2
        # pun = 2
        # cn = 2

        # 1 1 2 3 3 -> 1 2 3 3 -> 1 2 3
        # pun = 2
        # cn = 3

        while currNode:
            if currNode.val != prevUniqueNode.val:
                prevUniqueNode.next = currNode
                prevUniqueNode = currNode
            
            if not currNode.next and currNode.val == prevUniqueNode.val:
                prevUniqueNode.next = None
            
            currNode = currNode.next
        
        return head