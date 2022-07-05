// 反转链表练习
#include "include/linked_list.hpp"

class Solution {
public:
	ListNode* plusOne(ListNode* head)
	{
		head = revList(head);
		int carry = 1;
		ListNode* cursor = head;
		while (carry && cursor) {
			int val = carry + cursor->val;
			carry = val / 10;
			val = val % 10;
			cursor->val = val;
			if (cursor->next == nullptr && carry) {
				cursor->next = new ListNode(0);
			}
			cursor = cursor->next;
		}
		return revList(head);
	}

private:
	ListNode* revList(ListNode* head)
	{
		if (head == nullptr)
			return head;
		ListNode* prev = nullptr;
		while (head->next != nullptr) {
			ListNode* next = head->next;
			head->next = prev;
			prev = head;
			head = next;
		}
		head->next = prev;
		return head;
	}
};
