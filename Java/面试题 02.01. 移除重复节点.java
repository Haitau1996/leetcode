/*
执行用时：4 ms, 在所有 Java 提交中击败了95.00% 的用户
内存消耗：39.8 MB, 在所有 Java 提交中击败了42.48% 的用户
注意的点：
1. java 中的 HashSet 插入是可以返回状态的
2. 可以使用虚的表头
*/
class Solution {
    public ListNode removeDuplicateNodes(ListNode head) {
        HashSet<Integer> node = new HashSet<Integer>();
        ListNode virtNode = new ListNode(0);
        virtNode.next = head;
        ListNode cursor = virtNode;
        while(cursor.next != null){
            boolean status = node.add(cursor.next.val);
            if(status){
                cursor = cursor.next;
            }
            else{
                cursor.next = cursor.next.next;
            }
        }
        return virtNode.next;
    }
}