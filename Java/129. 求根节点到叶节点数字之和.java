/*
执行用时：0 ms, 在所有 Java 提交中击败了100.00% 的用户
内存消耗：35.8 MB, 在所有 Java 提交中击败了59.81% 的用户
*/
class Solution {
    public int sumNumbers(TreeNode root) {
        pathVal(root, 0);
        return Sum;
    }
    private void pathVal(TreeNode root, int father){
        if(root == null) return;
        else if(isLeaf(root)) {
            Sum = Sum + root.val + father * 10;
            return;
        }
        pathVal(root.left, father*10 + root.val);
        pathVal(root.right, father*10 + root.val);
    }
    private boolean isLeaf(TreeNode node){
        return node != null && node.left == null && node.right == null;
    }
    private int Sum = 0;
}
