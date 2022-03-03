class Solution {
public:
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* prev_a = list1;
        int count = 0;
        while(count < a-1){
            prev_a = prev_a->next;
            ++count;
        }
        ListNode* node_b = prev_a;
        while(count < b){
            node_b = node_b->next;
            ++count;
        }
        prev_a->next = list2;
        while(prev_a->next != nullptr){
            prev_a = prev_a->next;
        }
        prev_a->next = node_b->next;
        node_b->next = nullptr;
        return list1;
    }
};