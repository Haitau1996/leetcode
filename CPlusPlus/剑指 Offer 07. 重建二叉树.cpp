/*
执行用时：16 ms, 在所有 C++ 提交中击败了65.98%的用户
内存消耗：24.5 MB, 在所有 C++ 提交中击败了78.22%的用户
*/
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return buildTreeHelper(preorder,0, preorder.size()-1, inorder,0, inorder.size()-1);
    }
    TreeNode* buildTreeHelper(vector<int>& preOrder, int preBeg, int preEnd,
                              vector<int>& inOrder, int inBeg, int inEnd){
        if(preBeg > preEnd) return nullptr;
        else if(preBeg == preEnd){
            TreeNode* rootNode = new TreeNode(preOrder[preBeg]);
            return rootNode;
        }
        else{
            int root = preOrder[preBeg];
            TreeNode* rootNode = new TreeNode(preOrder[preBeg]);
            int rootIndex;
            for(rootIndex = inBeg; rootIndex < inEnd; ++rootIndex){
                if(inOrder[rootIndex] == root)
                    break;
            }
            int leftSize = rootIndex - inBeg;
            rootNode->left = buildTreeHelper(preOrder,preBeg+1, preBeg + leftSize,
                                         inOrder, inBeg, rootIndex-1);
            rootNode->right = buildTreeHelper(preOrder, preBeg + 1 + leftSize, preEnd,
                                              inOrder, rootIndex+1, inEnd);
            return rootNode;
        }
    }
};