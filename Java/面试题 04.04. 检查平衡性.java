/*
执行用时：1 ms, 在所有 Java 提交中击败了87.51% 的用户
内存消耗：38.7 MB, 在所有 Java 提交中击败了9.65% 的用户
同样的题目很简单， 需要注意的点是：
* 递归不能忘记了 base case 
*/

class Solution {
    public boolean isBalanced(TreeNode root) {
        if(deepth(root)<= 1) return true;
        return ( Math.abs(deepth(root.left) - deepth(root.right)) <=1) &&
                isBalanced(root.left)&&
                isBalanced(root.right);
    }
    private int deepth(TreeNode root){
        if(root == null)
            return 0;
        else{
            return 1 + Math.max(deepth(root.left),deepth(root.right));
        }
    }
}
