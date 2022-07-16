/*
 * 字典树可以实现一个字典， 然后使用深度优先搜索做查找.
 * 查找的时候， 先替换一个字符， 然后查找剩下的部分是不是在字典里， 不在的话替换下一个字符。 查找一个单词的时间复杂度为 O(\Sigma n^2), 其中 \Sigma 为字符集的个数, n为字符长度 在最坏的情况下， 每个字符都要替换， 每个替换的深度优先查找需要的时间复杂度为 n
*/
#include <string>
#include <vector>

using namespace std;
struct Trie{
    bool is_world;
    vector<Trie*> children;
    Trie():is_world(false), children(vector<Trie*>(26,nullptr)){};
};
class MagicDictionary {
    using TriePtr = Trie*;
public:
    MagicDictionary() {
        root = new Trie();
    }
    
    void buildDict(vector<string> dictionary) {
        for(const auto& w :dictionary){
            insert(w);
        }
    }
    
    bool search(string searchWord) {
        TriePtr curr = root;
        int idx = 0;
        while(idx < searchWord.size()&& curr != nullptr){
            for(int i = 0; i < 26; ++i){
                if((int)(searchWord[idx]-'a') != i && serach_remain(searchWord, idx+1, curr->children[i])) return true;
            }
            curr = curr->children[searchWord[idx]-'a'];
            ++idx;
        }
        return false;
    }
private:
    TriePtr root;
    void insert(const string& s){
        TriePtr curr = root;
        for(const auto c : s){
            if(curr->children[c-'a'] == nullptr){
                curr->children[c-'a'] = new Trie();
            }
            curr = curr -> children[c-'a'];
        }
        curr -> is_world = true;
    }
    bool serach_remain(string& s, int idx, TriePtr curr){
        if(curr == nullptr) return false;
        if(idx == s.size() && curr->is_world) return true;
        else if(idx >= s.size()) return false;
        else {
            return serach_remain(s, idx+1, curr->children[s[idx]-'a']);
        }
    }
};
