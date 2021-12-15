/*
执行用时：0 ms, 在所有 Java 提交中击败了100.00% 的用户
内存消耗：38.2 MB, 在所有 Java 提交中击败了43.07% 的用户
*/
class Solution {
    public ListNode reverseList(ListNode head) {
        if(head == null || head.next == null) return head;
        ListNode slow = head;
        ListNode fast = head.next;
        slow.next = null;
        while(fast!=null){
            ListNode temp = fast.next;
            fast.next = slow;
            slow = fast;
            fast = temp;
        }
        return slow;
    }
}