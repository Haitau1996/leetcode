/*
典型的递归求解，需要注意几个细节：
1. 使用 range-base loop 方便确定范围
2. 使用值传递数据， 因为引用传递可能后续会修改值
3. 为空的时候， 里面放一个 nullptr, 而不是直接返回一个 size 为 0 的 vector, 这样更方便地使用 range-based for loop
*/
class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        return genTreeInRange(1,n);
    }
private:
    vector<TreeNode*> genTreeInRange(int start, int end){
        if(start > end) return vector<TreeNode*>{nullptr};
        if(start == end) return vector<TreeNode*>{new TreeNode(start)};
        vector<TreeNode*> result{};
        for(int i = start; i <= end; ++i){
            vector<TreeNode*> left = genTreeInRange(start, i - 1);
            vector<TreeNode*> right = genTreeInRange(i + 1, end);
            for(auto leftSubTree: left){
                for(auto rightSubTree: right){
                    TreeNode* root = new TreeNode(i);
                    root -> left = leftSubTree;
                    root ->right = rightSubTree;
                    result.push_back(root);
                }
            }
        }
        return result;
    }
};