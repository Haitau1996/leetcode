/*
执行用时：44 ms, 在所有 C++ 提交中击败了76.16% 的用户
内存消耗：32.9 MB, 在所有 C++ 提交中击败了31.62% 的用户
*/
class Solution {
public:
    bool isSubStructure(TreeNode* A, TreeNode* B) {
        if(B == NULL || A == NULL)
            return false;
        if(A->val == B->val)
            if(checkStructure(A,B))
                return true;
        return isSubStructure(A->left,B) || isSubStructure(A->right,B);
    }
private:
    bool checkStructure(TreeNode* A, TreeNode* B){
        if(B == NULL)
            return true;
        if(A == NULL)
            return false;
        return  A-> val == B->val &&
                checkStructure(A->left,B->left) &&
                checkStructure(A->right,B->right);
    }
};