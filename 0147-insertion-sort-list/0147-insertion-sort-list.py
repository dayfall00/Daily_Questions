class Solution:
    def insertionSortList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if head is None or head.next is None:
            return head

        dummy = ListNode(0)
        dummy.next = head

        pre = head
        cur = head.next

        while cur:

            if cur.val >= pre.val:
                pre = cur
                cur = cur.next
                continue

            # Remove cur from its current position
            pre.next = cur.next

            # Find insertion position
            temp = dummy
            while temp.next.val < cur.val:
                temp = temp.next

            # Insert cur
            cur.next = temp.next
            temp.next = cur

            # Move to next node
            cur = pre.next

        return dummy.next