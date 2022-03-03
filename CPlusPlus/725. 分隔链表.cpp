/*
要格外小心遍历时候使用的下标， 很多时候 i j 弄混了怎么 debug 都 debug 不出来
*/
class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        ListNode* cursor = head;
        int node_count = 0;
        while(cursor){
            ++node_count;
            cursor = cursor-> next;
        }
        int average = node_count / k;
        int remainder = node_count % k;
        vector<ListNode*> result{};
        cursor = head;
        for(int i = 0; i < remainder; ++i){
            result.push_back(cursor);
            for(int j = 0; j < average; ++j){
                cursor = cursor-> next;
            }
            ListNode* next = cursor? cursor->next : nullptr;
            if(next) cursor->next = nullptr;
            if(cursor) cursor = next;
        }
        for(int i = remainder; i < k; ++i){
            result.push_back(cursor);
            for(int j = 0; j < average-1; ++j){
                cursor = cursor->next;
            }
            ListNode* next = cursor? cursor->next : nullptr;
            if(next) cursor->next = nullptr;
            if(cursor) cursor = next;
        }
        return result;
    }
};