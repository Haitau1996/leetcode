// 简单题， 只需要注意别忘记剩余部分

#include "include/linked_list.hpp"

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2)
    {
        ListNode* res = new ListNode(-1);
        ListNode* cursor = res;
        while (list1 && list2) {
            if (list1->val < list2->val) {
                cursor->next = list1;
                list1 = list1->next;
                cursor = cursor->next;
            } else {
                cursor->next = list2;
                list2 = list2->next;
                cursor = cursor->next;
            }
        }
        if (list1)
            cursor->next = list1;
        else
            cursor->next = list2;
        return res->next;
    }
};
