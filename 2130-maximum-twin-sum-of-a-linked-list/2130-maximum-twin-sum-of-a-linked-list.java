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
    public int pairSum(ListNode head) {
        ListNode curr = head;
        List<Integer> v = new ArrayList<>();
        while(curr != null){
            v.add(curr.val);
            curr = curr.next;
        }
        int l = 0, r = v.size()-1, ans = 0;
        while(l < r){
            ans = Math.max(ans, v.get(l)+v.get(r));
            l++;
            r--;
        }
        return ans;
    }
}