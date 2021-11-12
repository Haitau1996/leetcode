/*
执行用时：1278 ms, 在所有 Java 提交中击败了5.01% 的用户
内存消耗：40.4 MB, 在所有 Java 提交中击败了77.11% 的用户
*/
class Solution {
    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        while(root != p && root != q){
            if(isParents(root.left,p)){
                if(isParents(root.left,q)) root = root.left;
                else return root; 
            }
            else {
                if(isParents(root.right,q)) root = root.right;
                else return root;
            }
        }
        return root;
    }
    private boolean isParents(TreeNode root, TreeNode p){
        if(root == null) return false;
        if(root == p)   return true;
        return isParents(root.left, p) || isParents(root.right,p);
    }
}