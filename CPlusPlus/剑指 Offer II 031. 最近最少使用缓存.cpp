/*
* 使用一个双向链表来实现最久未使用缓存的删除
* 过去做的链表里面都只放了一个 val, 这里存放了 key 和 val
* 这个题目主要是要用一个 key->NodePointer 的哈希表实现 0(1) 的查找
* 添加值的时候记得将 currentSize++
*/
#include  <unordered_map>
using namespace std;
struct myDoubleNode{
    int key;
    int val;
    myDoubleNode* prev = nullptr;
    myDoubleNode* next = nullptr;
    myDoubleNode(int key, int val):key(key), val(val){}
};
typedef myDoubleNode* DLList;
typedef myDoubleNode* NodePtr;
class LRUCache {
public:
    LRUCache(int capacity):CAPACITY(capacity),currentSize(0) {
        head = new myDoubleNode(-1,-1);
        tail = new myDoubleNode(-1,-1);
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        auto iter = keyToPos.find(key);
        if(iter == keyToPos.end()) return -1;
        else{
            auto currentNode = iter->second;
            removeNode(currentNode);
            addHead(currentNode);
            return currentNode->val;
        }
    }
    
    void put(int key, int value) {
        auto iter = keyToPos.find(key);
        if(iter == keyToPos.end()){
            auto newNode = new myDoubleNode(key, value);
            if(currentSize == CAPACITY){
                auto nodeToRemove = tail->prev;
                removeNode(nodeToRemove);
                auto iterToRemove = keyToPos.find(nodeToRemove->key);
                if(iterToRemove != keyToPos.end()) keyToPos.erase(iterToRemove);
            }
            else currentSize++;
            addHead(newNode);
            keyToPos.insert(std::make_pair(key, newNode));
        }
        else{
            auto currentNode = iter -> second;
            currentNode->val = value;
            removeNode(currentNode);
            addHead(currentNode);
        }
    }
private:
    unordered_map<int, NodePtr> keyToPos;
    int CAPACITY;
    int currentSize;
    DLList head;
    DLList tail;
    void removeNode(NodePtr currentNode){
        NodePtr prevNode = currentNode -> prev;
        NodePtr nextNode = currentNode ->next;
        prevNode -> next = nextNode;
        nextNode -> prev = prevNode;
        currentNode -> prev = nullptr;
        currentNode -> next = nullptr;
    }
    void addHead(NodePtr currentNode){
        NodePtr oldHead = head->next;
        head-> next = currentNode;
        currentNode->prev = head;
        currentNode->next = oldHead;
        oldHead->prev = currentNode;
    }
};