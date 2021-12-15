/*
执行用时：0 ms, 在所有 Java 提交中击败了100.00% 的用户
内存消耗：38.4 MB, 在所有 Java 提交中击败了60.55% 的用户
*/
public class Solution {
    public ListNode detectCycle(ListNode head) {
        if(head==null || head.next == null) return null;
        ListNode slow = head;
        ListNode fast = head.next;
        while(fast!= slow){
            if(fast == null || fast.next == null) return null;
            fast = fast.next.next;
            slow = slow.next;
        }
        fast = fast.next;
        int circleLen = 1;
        while(fast != slow){
            fast = fast.next;
            circleLen++;
        }
        fast = head;
        slow = head;
        for(int i = 0; i < circleLen; i++){
            fast = fast.next;
        }
        while(fast != slow){
            fast = fast.next;
            slow = slow.next;
        }
        return slow;
    }
}