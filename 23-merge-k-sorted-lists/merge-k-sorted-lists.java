/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode merge(ListNode l1, ListNode l2) {

        if(l1 == null)
            return l2;
        if(l2 == null)
            return l1;

        if(l1.val < l2.val) {
            l1.next = merge(l1.next, l2);
            return l1;
        }
        else {
            l2.next = merge(l1, l2.next);
            return l2;
        }
    }
    public ListNode partition(ListNode[] lists, int s, int e) {
            if(s == e)
                return lists[s];
            
            int mid = s + (e - s) / 2;

            ListNode l1 = partition(lists, s, mid);
            ListNode l2 = partition(lists, mid + 1, e);

            return merge(l1, l2);
        }
    public ListNode mergeKLists(ListNode[] lists) {

        int n = lists.length;

        if(n == 0)
            return null;
            
        return partition(lists, 0, n - 1);

    }
}