#include <vector>
#include<string>
using namespace std;
struct MyNode{
    vector<MyNode*> children;
    bool isString{false};
    MyNode():children(26,nullptr){}
};
typedef MyNode* TrieNodePtr;
class Trie {
public:
    /** Initialize your data structure here. */
    Trie() {
        dummyRoot = new MyNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNodePtr cursor = dummyRoot;
        for(int i = 0; i<word.size(); ++i){
            int pos = word[i] - 'a';
            if(cursor->children[pos] == nullptr)
                cursor->children[pos] = new MyNode();
            cursor = cursor->children[pos]; 
        }
        cursor->isString = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNodePtr cursor = dummyRoot;
        for(int i = 0; i < word.size(); ++i){
            int pos = word[i] - 'a';
            if(cursor->children[pos] == nullptr) return false;
            cursor = cursor->children[pos];
        }
        return cursor->isString;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNodePtr cursor = dummyRoot;
        for(int i = 0; i < prefix.size(); ++i){
            int pos = prefix[i] - 'a';
            if(cursor->children[pos] == nullptr) return false;
            cursor = cursor->children[pos];
        }
        return true;
    }
private:
    TrieNodePtr dummyRoot;
};