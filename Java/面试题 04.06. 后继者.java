/*
执行用时：2 ms, 在所有 Java 提交中击败了100.00% 的用户
内存消耗：39.3 MB, 在所有 Java 提交中击败了38.25% 的用户
有下面几点需要注意的：
1. 分类讨论很重要， 就是对于节点的位置在左子树、右子树的讨论
2. 在右子树的时候， 需要找到第一个父节点， 使得它在节点的左边， 要一直向上寻找
3. 树是一个二叉搜索树， 我没有利用到其性质
*/

class Solution {
    public TreeNode inorderSuccessor(TreeNode root, TreeNode p) {
        // case 1: p 点有右子树
        if(root == null || (root == p && root.right ==null))
            return null;
        if(p.right != null)
            return findLeftMost(p.right);
        else{
            TreeNode fatherOfP = findFather(root, p);
            if(fatherOfP.left == p)
                return fatherOfP;
            else{
                while(fatherOfP != null && fatherOfP.left != p){
                    p = fatherOfP;
                    fatherOfP = findFather(root, p);
                }
                return fatherOfP;
            }
        }
    }
    private TreeNode findFather(TreeNode root, TreeNode p){
        if(root == p) return null;
        if(!isParents(root,p))
            return null;
        else if(!isParents(root.left,p) && !isParents(root.right,p))
            return root;
        else if(isParents(root.left,p))
            return findFather(root.left,p);
        else return findFather(root.right,p);
    }
    private boolean isParents(TreeNode root, TreeNode p){
        // base case:
        if(root == null)
            return false;
        if(root == p)
            return false;
        else if(root.left == p || root.right ==p)
            return true;
        else if(root.left == null && root.right == null)
            return false;
        else return isParents(root.left, p) || isParents(root.right,p);
    }
    private TreeNode findLeftMost(TreeNode root){
        while(root.left != null){
            root = root.left;
        }
        return root;
    }
}
