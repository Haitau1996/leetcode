// 理解了水塘抽样的具体想法

class Solution {
public:
    Solution(ListNode* head){
        this->head = head;
    }
    
    int getRandom() {
        int cnt = 0;
        int res = 0;
        ListNode* cursor = head;
        while(cursor!= nullptr){
            if(std::rand() % (cnt+1) == 0)
                res = cursor->val;
            ++cnt;
            cursor = cursor->next;
        }
        return res;
    }
private:
    ListNode* head;
};
