/*
没什么特别的，就是使用 queue 做二叉树的层次遍历
*/
#include <queue>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution {
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        queue<TreeNode*> working_queue{};
        queue<TreeNode*> queue_copy{};
        working_queue.push(original);
        queue_copy.push(cloned);
        while(!working_queue.empty()){
            auto current = working_queue.front();
            working_queue.pop();
            auto current_copy = queue_copy.front();
            queue_copy.pop();
            if(current == target) return current_copy;
            else{
                if(current->left){
                    working_queue.push(current->left);
                    queue_copy.push(current_copy->left);
                }
                if(current->right){
                    working_queue.push(current->right);
                    queue_copy.push(current_copy->right);
                }
            }
        }
        return nullptr;
    }
};
