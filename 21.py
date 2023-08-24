


# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def mergeTwoLists(self, list1: Optional[ListNode], list2: Optional[ListNode]) -> Optional[ListNode]:
        if not list1:
            return list2
        
        if not list2:
            return list1

        newHead = None
        
        if list1.val < list2.val:
            newHead = list1
            list1 = list1.next
        else:
            newHead = list2
            list2 = list2.next

        currNode = newHead
        
        while True:
            if list1 is None:
                currNode.next = list2
                return newHead
            
            if list2 is None:
                currNode.next = list1
                return newHead

            if list1.val < list2.val:
                currNode.next = list1
                currNode = currNode.next
                list1 = list1.next
            else:
                currNode.next = list2
                currNode = currNode.next
                list2 = list2.next


        return newHead
        


        
