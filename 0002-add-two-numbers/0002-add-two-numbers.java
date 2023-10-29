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
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        ListNode ans = new ListNode();
        ListNode curr = ans;
        int d1, d2, sum, carry = 0;
        while(l1!=null || l2!=null){
            d1 = 0; d2 = 0;
            if(l1!=null){
                d1 = l1.val;
                l1 = l1.next;
            }
            if(l2!=null){
                d2 = l2.val;
                l2 = l2.next;
            }
            sum = d1+d2+carry;
            carry = sum/10;
            curr.next = new ListNode(sum%10);
            curr = curr.next;
        }
        while(carry!=0){
            curr.next = new ListNode(carry%10);
            carry /= 10;
        }
        return ans.next;
    }
}