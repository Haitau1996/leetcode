/*
* 记得使用 std::remove(list.begin(), list.end(),nullptr) 去除空指针
*/
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        auto cmp = [](ListNode* prev, ListNode* next){
            return prev->val > next->val;
        };
        auto noNullptrEnd = std::remove(lists.begin(), lists.end(), nullptr);
        lists.erase(noNullptrEnd, lists.end());
        if(!lists.empty()) std::make_heap(lists.begin(),lists.end(),cmp);
        ListNode* dummy = new ListNode();
        ListNode* cursor = dummy;
        while(lists.size() != 0){
            auto smallest = lists[0];
            auto to_push = smallest -> next;
            cursor -> next = smallest;
            std::pop_heap(lists.begin(),lists.end(),cmp);
            lists.pop_back();
            if(to_push){
                lists.push_back(to_push);
                std::push_heap(lists.begin(), lists.end(),cmp);
            }
            cursor = cursor->next;
            cursor -> next = nullptr;
        }
        return dummy->next;
    }
};