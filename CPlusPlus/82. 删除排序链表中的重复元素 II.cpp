/*
 * 解法 1： 双指针， 遇到相等的节点就跳过
 * 解法 2： 递归
 */
#include "include/linked_list.hpp"
class DualPtrSolution {
public:
    ListNode* deleteDuplicates(ListNode* head)
    {
        if (head == nullptr || head->next == nullptr)
            return head;
        ListNode* virtualNode = new ListNode(0);
        virtualNode->next = head;
        ListNode* cursor = virtualNode;
        while (cursor->next != nullptr && cursor->next->next != nullptr) {
            if (cursor->next->val != cursor->next->next->val)
                cursor = cursor->next;
            else {
                ListNode* toDelete = cursor->next;
                while (toDelete->next != nullptr) {
                    if (toDelete->next->val != toDelete->val)
                        break;
                    else
                        toDelete = toDelete->next;
                }
                cursor->next = toDelete->next;
            }
        }
        return virtualNode->next;
    }
};

class RecursiveSolution {
public:
    ListNode* deleteDuplicates(ListNode* head)
    {
        if (head == nullptr || head->next == nullptr)
            return head;
        if (head->next->val != head->val) {
            head->next = deleteDuplicates(head->next);
        } else {
            int val = head->val;
            while (head != nullptr && head->val == val) {
                head = head->next;
            }
            head = deleteDuplicates(head);
        }
        return head;
    }
};
