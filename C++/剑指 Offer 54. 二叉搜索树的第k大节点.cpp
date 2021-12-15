/*
执行用时：20 ms, 在所有 C++ 提交中击败了40.63% 的用户
内存消耗：23.4 MB, 在所有 C++ 提交中击败了76.38% 的用户
* 是最大的节点而不是最小的
*/
class Solution {
public:
    int kthLargest(TreeNode* root, int k) {
        int rightSize = TreeSize(root->right);
        if(rightSize == k-1) return root->val;
        else if(rightSize > k-1) return kthLargest(root->right,k);
        else return kthLargest(root->left, k-rightSize-1);
    }
private:
    int TreeSize(TreeNode* root){
        // base case: the root is null
        if(root == nullptr) return 0;
        else return 1 + TreeSize(root->left) + TreeSize(root->right);
    }
};