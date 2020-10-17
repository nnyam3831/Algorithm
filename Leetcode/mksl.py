from queue import PriorityQueue
# Leetcode no.23 Merge k Sorted Lists

# Definition for singly-linked list.


class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


# class Solution:
#     def checkAll(self, lists):
#         ret = True
#         for i in range(len(lists)):
#             if lists[i]:
#                 ret = False
#                 break
#         return ret

#     def mergeKLists(self, lists: [ListNode]) -> ListNode:
#         dummy = ListNode()
#         head = dummy

#         while not self.checkAll(lists):
#             current_value, current_index = 10000000, None
#             for i in range(len(lists)):
#                 if not lists[i]:
#                     continue
#                 if lists[i].val <= current_value:
#                     current_value, current_index = lists[i].val, i

#             head.next = ListNode(current_value)
#             head, lists[current_index] = head.next, lists[current_index].next

#         return dummy.next

class Solution:
    def mergeKLists(self, lists: [ListNode]) -> ListNode:
        sorted_list_head = sorted_list_tail = ListNode(0)

        pq = PriorityQueue()

        def add_node_in_pq(idx, node):
            if node:
                pq.put((node.val, idx, node))

        for idx, node in enumerate(lists):
            add_node_in_pq(idx, node)

        while not pq.empty():
            _, idx, node = pq.get()
            add_node_in_pq(idx, node.next)
            node.next = None
            sorted_list_tail.next = node
            sorted_list_tail = sorted_list_tail.next

        return sorted_list_head.next


node1 = ListNode(1)
node1.next = ListNode(4)
node1.next.next = ListNode(5)

node2 = ListNode(1)
node2.next = ListNode(3)
node2.next.next = ListNode(4)

node3 = ListNode(2)
node3.next = ListNode(6)

sol = Solution()
sol.mergeKLists([node1, node2, node3])
