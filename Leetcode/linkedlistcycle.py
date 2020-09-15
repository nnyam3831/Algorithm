# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None


# value가 유일하다는 조건이 없으므로 head 자체(메모리를 저장해야됨)
# O(N)
class Solution:
    def hasCycle(self, head) -> bool:
        node_dict = {}
        while head != None:
            if node_dict.get(head):
                return True

            node_dict[head] = 1
            head = head.next
        return False
