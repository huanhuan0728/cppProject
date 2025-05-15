/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     public int val;
 *     public ListNode next;
 *     public ListNode(int val=0, ListNode next=null) {
 *         this.val = val;
 *         this.next = next;
 *     }
 * }
 */
public class Solution
{
    public ListNode SwapPairs(ListNode head)
    {
        ListNode dummy = new ListNode(0, head);
        ListNode cur = dummy;

        while (cur.next != null && cur.next.next != null)
        {
            ListNode first = cur.next;
            ListNode second = cur.next.next;

            cur.next = second;
            first.next = second.next;
            second.next = first;

            cur = first;
        }

        return dummy.next;
    }
}