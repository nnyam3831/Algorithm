class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


def solution(l1, l2):
    ret = ListNode()
    cur = ret
    while l1 and l2:
        if l1.val > l2.val:
            cur.next = ListNode(l2.val)
            cur = cur.next
            l2 = l2.next
        else:
            cur.next = ListNode(l1.val)
            cur = cur.next
            l1 = l1.next

    if l1:
        cur.next = ListNode(l1.val)
        cur = cur.next
        l1 = l1.next
    elif l2:
        cur.next = ListNode(l2.val)
        cur= cur.next
        l2 = l2.next
    
    return ret
