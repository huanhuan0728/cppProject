class ListNode:
    def __init__(self, val=0, next = None):
        self.val = val
        self.next = next

class Solution:
    def swapPairs(self, head:ListNode) ->ListNode:
        dummy = ListNode(-1)
        dummy.next = head
        cur = dummy

        while cur.next and cur.next.next:
            first = cur.next
            second = cur.next.next

            first.next = second.next
            second.next = first
            cur.next = second

            cur = first
        return dummy.next

