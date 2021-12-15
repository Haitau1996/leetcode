/*
执行用时：2 ms, 在所有 Java 提交中击败了92.58% 的用户
内存消耗：38.8 MB, 在所有 Java 提交中击败了30.79% 的用户
*/
class Solution {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        l1 = revList(l1);
        l2 = revList(l2);
        return addReversed(l1,l2);
    }
    private ListNode revList(ListNode head){
        if(head == null || head.next == null) return head;
        ListNode fast = head.next;
        ListNode slow = head;
        slow.next = null;
        while(fast!=null){
            ListNode temp = fast.next;
            fast.next = slow;
            slow = fast;
            fast = temp;
        }
        return slow;
    }
    private ListNode addReversed(ListNode l1, ListNode l2){
        int carry = 0;
        ListNode vNode = new ListNode(0);
        ListNode cursor1 = vNode;
        ListNode cursor2 = new ListNode(0);
        cursor1.next = l1;
        cursor2.next = l2;
        while(cursor1.next != null && cursor2.next!= null){
            cursor1.next.val = cursor1.next.val + cursor2.next.val + carry;
            if(cursor1.next.val >= 10){
                cursor1.next.val -= 10;
                carry = 1;
            }
            else carry = 0;
            cursor1 = cursor1.next;
            cursor2 = cursor2.next;
        }
        if(cursor1.next == null){
            cursor1.next = cursor2.next;
        }
        while(carry!= 0 && cursor1.next != null){
            cursor1.next.val += 1;
            if(cursor1.next.val >= 10){
                carry = 1;
                cursor1.next.val -=10;
            }
            else carry = 0;
            cursor1 = cursor1.next;
        }
        if(carry != 0) cursor1.next = new ListNode(1);
        return revList(vNode.next);
    }
}