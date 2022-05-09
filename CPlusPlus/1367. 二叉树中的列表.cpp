/*
 深度优先搜索查找是否存在满足条件的节点， 分两种情况
1. 以 root 为起点的链接符合条件， 在函数 core 中处理
2. 如果 root 不满足， 则递归处理看左右能否找到

DFS 递归求解要处理 base case, 需要注意的是整体的 base case 和 core 中 base case 情况是不同的：
1. 整体的 base case 在 root->val 和 head->val 不相等的时候是可以遍历子树的
2. 而 core 中一旦满足 root->val != head->val 说明链条已经中断， 直接返回 false
*/
class Solution {
public:
    bool isSubPath(ListNode* head, TreeNode* root) {
        if(head == nullptr) return true;
        if(root == nullptr) return false;
        return  core(head,root)||
                isSubPath(head, root->left) ||
                isSubPath(head, root->right);
    }
private:
    bool core(ListNode* head, TreeNode* root){
        if(head == nullptr) return true;
        if(root == nullptr || root->val != head->val) return false;
        return core(head->next, root->left) || core(head->next, root->right);
    }
};
