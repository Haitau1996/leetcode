#include <unordered_map>
#include "include/linked_list.hpp"

using namespace std;
class Solution {
public:
    ListNode* deleteDuplicatesUnsorted(ListNode* head) {
        ListNode* cursor = head;
        while(cursor != nullptr){
            val_cnt[cursor->val]++;
            cursor = cursor->next;
        }
        return dfs(head);
    }
private:
    unordered_map<int, int> val_cnt{};
    ListNode* dfs(ListNode* head){
        if(head == nullptr) return head;
        head->next = dfs(head->next);
        if(val_cnt[head->val] > 1) return head->next;
        return head;
    }
};
