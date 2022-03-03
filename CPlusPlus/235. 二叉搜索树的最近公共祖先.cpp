/*
执行用时：28 ms, 在所有 C++ 提交中击败了89.92% 的用户
内存消耗：22.6 MB, 在所有 C++ 提交中击败了95.58% 的用户
*/
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root->val == p->val)
            return p;
        if(root->val == q->val)
            return q;
        if(((root->val) - (p->val) )* ((root->val)-(q->val)) < 0)
            return root;
        else if((root->val)>(p->val))
            return lowestCommonAncestor(root->left,p,q);
        return lowestCommonAncestor(root->right,p,q);
    } 
};