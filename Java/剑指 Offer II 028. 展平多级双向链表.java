// 这道题目最重要的是使用递归从下到上展开， 然后和前面的部分连起来
class Solution {
    public Node flatten(Node head) {
        getTail(head);
        return head;
    }
    private Node getTail(Node head){
        Node cursor = head;
        Node tail = null;
        while(cursor!=null){
            Node next = cursor.next;
            if(cursor.child!=null){
                Node child = cursor.child;
                Node childTail = getTail(child);

                cursor.child = null;
                cursor.next = child;
                child.prev = cursor;
                childTail.next = next;
                if(next != null) next.prev = childTail;
                tail = childTail;
            }else{
                tail = cursor;
            }    
            cursor = cursor.next;
        }
        return tail;
    }
}