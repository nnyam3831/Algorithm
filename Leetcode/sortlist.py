class Solution(object):
    def sortList(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        if not head or not head.next:
            return head

        prev, slow, fast = head, head, head
        while fast and fast.next:
            prev = slow
            slow = slow.next
            fast = fast.next.next

        prev.next = None
        return self._merge(*map(self.sortList, (head, slow)))

    def _merge(self, l1, l2):
        dummy = p = ListNode(None)

        while l1 and l2:
            if l1.val < l2.val:
                p.next, l1 = l1, l1.next
            else:
                p.next, l2 = l2, l2.next
            p = p.next

        p.next = l1 or l2
        return dummy.next
