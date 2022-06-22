/*
 * 先抹平长度差， 然后挨个查找
 */
#include "include/linked_list.hpp"

class Solution {
public:
	ListNode* getIntersectionNode(ListNode* headA, ListNode* headB)
	{
		int lenA = get_len(headA);
		int lenB = get_len(headB);
		if (lenA > lenB) {
			headA = advance(headA, lenA - lenB);
		} else {
			headB = advance(headB, lenB - lenA);
		}
		while (headA != nullptr) {
			if (headB == headA) {
				break;
			} else {
				headA = headA->next;
				headB = headB->next;
			}
		}
		return headA;
	}

private:
	ListNode* advance(ListNode* curr, int n)
	{
		for (int i = 0; i < n; ++i) {
			curr = curr->next;
		}
		return curr;
	}
	int get_len(ListNode* curr)
	{
		int i = 0;
		while (curr != nullptr) {
			++i;
			curr = curr->next;
		}
		return i;
	}
};
