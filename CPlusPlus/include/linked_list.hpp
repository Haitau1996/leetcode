#ifndef _LEETCODE_LINKED_LIST_HPP
#define _LEETCODE_LINKED_LIST_HPP
struct ListNode {
    int val;
    ListNode* next;
    ListNode()
        : val(0)
        , next(nullptr)
    {
    }
    ListNode(int x)
        : val(x)
        , next(nullptr)
    {
    }
    ListNode(int x, ListNode* next)
        : val(x)
        , next(next)
    {
    }
};
#endif // _LEETCODE_LINKED_LIST_HPP