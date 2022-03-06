struct MyNode{
    int val;
    int key;
    MyNode* next;
    MyNode(int key,int val):key(key),val(val),next(nullptr){}
};
typedef MyNode* MyList;

class MyHashMap {
public:
    MyHashMap() {
        hash_table = vector<MyList>(103, new MyNode(-1,-1));
    }
    
    void put(int key, int value) {
        int pos = key % 103;
        MyNode* cursor = hash_table[pos];
        while(cursor->next != nullptr){
            if(cursor->key == key) {
                cursor->val = value;
                return;
            }
            else cursor = cursor->next;
        }
        cursor->key = key;
        cursor->val = value;
        cursor->next = new MyNode(-1,-1);
    }
    
    int get(int key) {
        int pos = key % 103;
        MyNode* cursor = hash_table[pos];
        while(cursor->next != nullptr){
            if(cursor->key == key) return cursor->val;
            else cursor = cursor->next;
        }
        return cursor->val;
    }
    
    void remove(int key) {
        int pos = key % 103;
        MyNode* cursor = hash_table[pos];
        while(cursor->next != nullptr){
            if(cursor->key == key){
                cursor->key = cursor->next->key;
                cursor->val = cursor->next->val;
                cursor->next = cursor->next->next;
                return;
            }
            else cursor = cursor->next;
        }
    }
private:
    vector<MyList> hash_table;
};