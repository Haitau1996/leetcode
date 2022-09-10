// 反转链表练习
#include "include/linked_list.hpp"

class Solution {
public:
	ListNode* plusOne(ListNode* head)
	{
		head = rev_list(head);
		head = plus_core(head);
		return rev_list(head);
	}

private:
	ListNode* rev_list(ListNode* head)
	{
		if (head == nullptr)
			return head;
		ListNode* prev = nullptr;
		ListNode* next = head->next;
		while (next != nullptr) {
			head->next = prev;
			prev = head;
			head = next;
			next = head->next;
		}
		head->next = prev;
		return head;
	}
	ListNode* plus_core(ListNode* head)
	{
		int val = 1;
		ListNode* dummy = new ListNode(-1);
		dummy->next = head;
		ListNode* cursor = dummy;
		while (cursor->next != nullptr && val) {
			int curr = cursor->next->val + val;
			cursor->next->val = curr % 10;
			val = curr / 10;
			cursor = cursor->next;
		}
		if (val)
			cursor->next = new ListNode(1);
		return dummy->next;
	}
};
