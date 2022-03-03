/*
执行用时：0 ms, 在所有 C++ 提交中击败了100.00% 的用户
内存消耗：9 MB, 在所有 C++ 提交中击败了10.88% 的用户
需要注意的点有：
*  需要加深 recursion 有理解
*  注意不要轻易使用 static 成员
*/

class Solution {
public:
    vector<int> reversePrint(ListNode* head) {
        helper(head);
        return res;
    }
    void helper(ListNode* head){
        if(head != NULL){
            if(head->next != NULL){
                helper(head->next);
            }
            res.push_back(head->val);
        }
    }
private:
    vector<int> res{};
};