/*
执行用时：4 ms, 在所有 C++ 提交中击败了88.14% 的用户
内存消耗：7.2 MB, 在所有 C++ 提交中击败了47.19% 的用户
* 要使用递归从下往上展开
* 不要忘记将 child 指针设置为 nullptr
*/
class Solution {
public:
    Node* flatten(Node* head) {
        getFlatTail(head);
        return head;
    }
    Node* getFlatTail(Node* head){
        Node* cursor = head;
        Node* tail = nullptr;
        while(cursor!=nullptr){
            if(cursor->child != nullptr){
                Node* child = cursor->child;
                cursor->child = nullptr;
                Node* next = cursor->next;
                Node* childTail = getFlatTail(child);
                cursor->next = child;
                child->prev = cursor;
                childTail -> next = next;
                if(next != nullptr) next->prev = childTail;
                tail = childTail;
            }
            else tail = cursor;
            cursor = cursor->next;
        }
        return tail;
    }
};