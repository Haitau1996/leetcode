/*
对于每个点， 我们使用 start_from 求解以它为起点的路径个数， 总的结果是 start_from(root) 和 pathSum(root->left) 和 pathSum(root->right) 之和， 可以递归求解
*/
class Solution {
public:
    int pathSum(TreeNode* root, int targetSum) {
        int result=0;
        result += start_from(root,targetSum);
        if(root!=nullptr) {
            result +=pathSum(root->left,targetSum);
            result +=pathSum(root->right,targetSum);
        }
        return result;
    }
private:
    int start_from(TreeNode* root, int targetSum){
        if(root == nullptr) return 0;
        else if(root->val == targetSum) return 1 + start_from(root->left, 0) + start_from(root->right,0);
        else return start_from(root->left, targetSum-root->val) + start_from(root->right, targetSum - root->val);
    }
};