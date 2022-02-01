/*
* 使用 merge sort 实现
* 使用了递归， 需要注意的是， 递归一定要有 base case
*/
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if(head == nullptr || head->next == nullptr) return head;
        ListNode* next = splitList(head);
        head = sortList(head);
        next = sortList(next);
        head = mergeList(head, next);
        return head; 
    }
private:
    ListNode* mergeList(ListNode* l1, ListNode* l2){
        ListNode* vNode= new ListNode(-1);
        ListNode* cursor = vNode;
        while(l1 != nullptr && l2!=nullptr){
            if(l1 -> val <= l2->val){
                cursor->next = l1;
                cursor = cursor->next;
                l1 = l1-> next;
            }
            else{
                cursor-> next = l2;
                cursor = cursor-> next;
                l2 = l2 -> next;
            }
        }
        if(l1 != nullptr){
            cursor->next = l1;
        }
        else{
            cursor->next = l2;
        }
        return vNode->next;
    }
    ListNode* splitList(ListNode* head){
        ListNode* fast = head->next;
        ListNode* slow = head;
        while(fast!=nullptr && fast->next != nullptr){
            fast = fast->next->next;
            slow = slow->next;
        }
        fast = slow->next;
        slow-> next = nullptr;
        return fast;
    }
};