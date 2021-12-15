/*
执行用时：1 ms, 在所有 Java 提交中击败了100.00% 的用户
内存消耗：41.4 MB, 在所有 Java 提交中击败了18.97% 的用户
*/
public class Solution {
    public ListNode getIntersectionNode(ListNode headA, ListNode headB) {
        int lenA = listLen(headA);
        int lenB = listLen(headB);
        ListNode longer = lenA>=lenB ? headA : headB;
        ListNode shorter = lenA >= lenB? headB : headA;
        int lenDiff = lenA>lenB ? (lenA -lenB) : (lenB-lenA);
        for(int i= 0; i<lenDiff; ++i){
            longer = longer.next;
        }
        while(longer != shorter){
            longer = longer.next;
            shorter = shorter.next;
        }
        return shorter;
    }
    private int listLen(ListNode head){
        int i = 0;
        while(head != null){
            ++i;
            head = head.next;
        }
        return i;
    }
}