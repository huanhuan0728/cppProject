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
public class ListNode
{

    public int val;
    public ListNode next;
    public ListNode(int val = 0; ListNode next = null){
        this.val = val;
        this.next = next;
    }}
public class Solution
{
    public ListNode RemoveNthFromEnd(ListNode head, int n)
    {
        ListNode dummyhead = new ListNode(0, head);
        ListNode slow = dummyhead;
        ListNode fast = dummyhead;

        while (n-- > 0 && fast != null)
        {
            fast = fast.next;
        }

        while (fast.next != null)
        {
            fast = fast.next;
            slow = slow.next;
        }

        slow.next = slow.next.next;

        return dummyhead.next;

    }
}