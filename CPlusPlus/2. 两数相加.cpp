// 链表常见的题目， 需要注意两个问题
// 1. 不要把 % 和 / 搞混， 前者求余数， 后者求商
// 2. 记得检查链表长度不一样的情况
#include "include/linked_list.hpp"

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {
        ListNode* res = new ListNode(-1);
        ListNode* cursor = res;
        int carrier = 0;
        while (l1 != nullptr && l2 != nullptr) {
            int current = l1->val + l2->val + carrier;
            cursor->next = new ListNode(current % 10);
            carrier = current / 10;
            cursor = cursor->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        if (l2)
            l1 = l2;
        while (l1) {
            int current = l1->val + carrier;
            cursor->next = new ListNode(current % 10);
            carrier = current / 10;
            cursor = cursor->next;
            l1 = l1->next;
        }
        if (carrier) {
            cursor->next = new ListNode(1);
        }
        return res->next;
    }
};
