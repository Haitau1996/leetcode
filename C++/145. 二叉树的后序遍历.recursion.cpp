class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
      postHelper(root);
      return res;
    }
private:
    void postHelper(TreeNode* root);
    vector<int> res{};
};

void Solution::postHelper(TreeNode* root){
        // base case: the tree node is null
      if(root == nullptr)
        return;
      else{  
        postHelper(root->left);
        postHelper(root->right);
        res.push_back(root->val);
      }
}