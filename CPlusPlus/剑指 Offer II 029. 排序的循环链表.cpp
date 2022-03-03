/*
执行用时：8 ms, 在所有 C++ 提交中击败了83.45% 的用户
内存消耗：8 MB, 在所有 C++ 提交中击败了34.80% 的用户
*
*/
class Solution {
public:
    Node* insert(Node* head, int insertVal) {
        if(head == nullptr){
            head = new Node(insertVal);
            head->next = head;
            return head;
        }
        Node* max = head;
        while(max->next != head && max->next->val >= max->val){
            max = max ->next;
        }
        Node* min = max->next;
        if(max->val <= insertVal || max->next->val >= insertVal){
            Node* toAdd = new Node(insertVal);
            max->next = toAdd;
            toAdd->next = min;
        }
        else{
            while(min->next->val <= insertVal){
                min = min->next;
            }
            Node* toAdd = new Node(insertVal);
            Node* post = min->next;
            min->next = toAdd;
            toAdd->next = post;
        }
        return head;
    }
};