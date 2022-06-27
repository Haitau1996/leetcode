/*
 * 解法 1： 使用 stack
 * 解法 2： 反转链表
 */
#include "include/linked_list.hpp"
#include <stack>

using namespace std;
class Solution1 {
public:
	void reorderList(ListNode* head)
	{
		// 先便利一遍看链表的长度
		ListNode* cursor = head;
		size_t listLength { 0 };
		while (cursor != nullptr) {
			++listLength;
			cursor = cursor->next;
		}
		std::stack<ListNode*> postStack;
		cursor = head;
		ListNode* postList;
		for (size_t i = 0; i < listLength / 2; ++i) {
			cursor = cursor->next;
		}
		postList = cursor->next;
		cursor->next = nullptr;
		while (postList != nullptr) {
			postStack.push(postList);
			postList = postList->next;
		}
		cursor = head;
		ListNode* temp;
		while (!postStack.empty()) {
			temp = cursor->next;
			cursor->next = postStack.top();
			cursor = cursor->next;
			cursor->next = temp;
			postStack.pop();
			cursor = cursor->next;
		}
	}
};
class Solution {
public:
	void reorderList(ListNode* head)
	{
		auto len = list_len(head);
		int steps = (len - 1) >> 1;
		ListNode* cursor = head;
		for (int i = 0; i < steps; ++i) {
			cursor = cursor->next;
		}
		ListNode* rear = cursor->next;
		cursor->next = nullptr;
		rear = rev_list(rear);
		cursor = head;
		while (cursor != nullptr) {
			ListNode* temp = cursor->next;
			cursor->next = rear;
			if (rear) {
				rear = rear->next;
				cursor->next->next = temp;
			}
			cursor = temp;
		}
	}

private:
	int list_len(ListNode* head)
	{
		int res = 0;
		while (head != nullptr) {
			head = head->next;
			++res;
		}
		return res;
	}
	ListNode* rev_list(ListNode* head)
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
