class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        auto end = std::remove_if(lists.begin(), lists.end(), [](ListNode* node){return node == nullptr;});
        lists.erase(end,lists.end());
        auto cmp = [](ListNode* a, ListNode* b){ return a->val > b->val;};
        std::make_heap(std::begin(lists), std::end(lists),cmp);
        ListNode* vNode = new ListNode(0);
        ListNode* cursor = vNode;
        while(lists.size()!=0){
            std::pop_heap(std::begin(lists), std::end(lists));
            ListNode* min = lists.back();
            ListNode* next = min->next;
            cursor->next = min;
            lists.pop_back();
            cursor = cursor->next;
            cursor->next = nullptr;
            if(next!=nullptr){
                lists.push_back(next);
            }
            std::make_heap(lists.begin(),lists.end(),cmp);
        }
        return vNode->next;
    }
};