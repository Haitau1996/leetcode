/**
 * 使用两个 queue 做层次遍历
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
    TreeNode* findNearestRightNode(TreeNode* root, TreeNode* u) {
        queue<TreeNode*> working_queue{};
        queue<TreeNode*> todo_queue{};
        working_queue.push(root);
        while(!working_queue.empty()){
            while(!working_queue.empty()){
                auto current =working_queue.front();
               working_queue.pop();
                if(current->val == u->val){
                    return (working_queue.empty() ? nullptr : working_queue.front());
                }
                else{
                    if(current -> left) todo_queue.push(current->left);
                    if(current -> right) todo_queue.push(current->right);
                }
            }
            swap(working_queue,todo_queue);
        }
        return nullptr;
    }
};
