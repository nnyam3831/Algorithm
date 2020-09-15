# Definition for singly-linked list.


class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

# dict에 넣고 처음 겹치는 곳이 시작점


class Solution:
    def detectCycle(self, head: ListNode) -> ListNode:
        node_dict = {}
        while head:
            if node_dict[head]:
                return head
            head = head.next

        return None
