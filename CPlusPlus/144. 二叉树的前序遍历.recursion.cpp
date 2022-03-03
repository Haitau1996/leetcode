/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
      preHelper(root);
      return res;
    }
private:
    void preHelper(TreeNode* root);
    vector<int> res{};
};

void Solution::preHelper(TreeNode* root){
        // base case: the tree node is null
      if(root == nullptr)
        return;
      else{
        res.push_back(root->val);
        preHelper(root->left);
        preHelper(root->right);
      }
}