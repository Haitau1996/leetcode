/*
执行用时：1 ms, 在所有 Java 提交中击败了99.79% 的用户
内存消耗：41 MB, 在所有 Java 提交中击败了51.54% 的用户
*/
class Solution {
    public void reorderList(ListNode head) {
        if(head == null || head.next == null || head.next.next == null) return;
        // step 1: 分割链表
        ListNode fastCur = head;
        ListNode slowCur = head;
        while(fastCur!=null && fastCur.next != null){
            fastCur = fastCur.next.next;
            slowCur = slowCur.next;
        }
        ListNode post = slowCur.next;
        slowCur.next = null;
        // 翻转后半部分
        post = revList(post);
        fastCur = head;
        // 合并链表
        ListNode tempPrev;
        ListNode tempPost;
        while(post!= null){
            tempPrev = fastCur.next;
            tempPost = post.next;
            fastCur.next = post;
            post.next = tempPrev;
            fastCur = tempPrev;
            post = tempPost;
        }
    }
    private ListNode revList(ListNode head){
        // base case: one or null node
        if(head == null || head.next == null) return head;
        ListNode fast = head.next;
        ListNode slow = head;
        slow.next = null;
        ListNode temp;
        while(fast!= null){
            temp = fast.next;
            fast.next = slow;
            slow = fast;
            fast = temp;
        }
        return slow;
    }
}