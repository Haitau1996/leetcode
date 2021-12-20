/*
执行用时：0 ms, 在所有 Java 提交中击败了100.00% 的用户
内存消耗：37.9 MB, 在所有 Java 提交中击败了74.47% 的用户
*/
class Solution {
    public Node copyRandomList(Node head) {
        copyList(head);
        copyRandomPtr(head);
        return seperateList(head);    
    }
    private void copyList(Node head){
        Node cursor = head;
        Node next = null;
        while(cursor != null){
            next = cursor.next;
            cursor.next = new Node(cursor.val);
            cursor.next.next = next;
            cursor = next;
        }
    }
    private void copyRandomPtr(Node head){
        Node cursor = head;
        Node copy = null;
        while(cursor!=null){
            copy = cursor.next;
            if(cursor.random != null){
                cursor.next.random = cursor.random.next;
            }
            cursor = copy.next;
        }

    }
    private Node seperateList(Node head){
        Node result = new Node(0);
        Node cursor = result;
        Node copy = null;
        while(head != null){
            copy = head.next;
            head.next = copy.next;
            cursor.next = copy;
            head = head.next;
            cursor = cursor.next;
        }
        return result.next;
    }
}