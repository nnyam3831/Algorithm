# leetcode no.162 Intersection of Two Linked Lists
# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None


# a로 사이클 만들고 b로 체크하기


# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

# class Solution:
#     def getIntersectionNode(self, headA: ListNode, headB: ListNode) -> ListNode:
#         p = headA
#         if p is None:
#             return None

#         while p.next != None:
#             p = p.next
#         p.next = headA

#         slow, fast = headB, headB
#         while fast != None and fast.next != None:
#             slow = slow.next
#             fast = fast.next.next
#             if slow == fast:
#                 break

#         if not fast or not fast.next:
#             p.next = None
#             return None

#         check = headB
#         while check != slow:
#             check = check.next
#             slow = slow.next

#         p.next = None
#         return slow

class Solution:
    def getIntersectionNode(self, headA, headB):
        if headA is None or headB is None:
            return None

        pa, pb = headA, headB

        while pa is not pb:
            pa = headB if pa is None else pa.next
            pb = headA if pb is None else pb.next

        return pa
