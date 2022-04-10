#include<string>
#include<unordered_set>
#include<vector>
using namespace std;
class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        char2morse = vector<string>{".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        unordered_set<string> res_set;
        for(const auto& elem : words){
            res_set.insert(word2morse(elem));
        }
        return res_set.size();
    }
private:
    vector<string> char2morse;
    string word2morse(const string& word){
        string res{};
        for(const auto& c : word){
            res+= char2morse[c-'a'];
        }
        return res;
    }
};
