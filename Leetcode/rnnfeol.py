# leetcode no.19 Remove Nth Node From End of List

# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def removeNthFromEnd(self, head: ListNode, n: int) -> ListNode:
        dummy, cur = ListNode(-1), head
        dummy.next = cur
        node_list = [dummy]
        while cur != None:
            node_list.append(cur)
            cur = cur.next

        prev, cur = node_list[-n-1], node_list[-n]
        prev.next = cur.next

        return dummy.next
