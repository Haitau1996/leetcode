class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        
        inorder(root);
        int beg = 0;
        int end = arr.size() - 1;
        while(beg < end){
            if(arr[beg] + arr[end] < k) ++beg;
            else if(arr[beg] + arr[end] == k) return true;
            else --end;
        }
        return false;
    }
private:
    vector<int> arr{};
    void inorder(TreeNode* root){
        if(root != nullptr){
            inorder(root->left);
            arr.push_back(root->val);
            inorder(root->right);
        }
    }
};