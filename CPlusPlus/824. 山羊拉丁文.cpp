#include<sstream>
#include<string>
#include<unordered_set>

using namespace std;
class Solution {
public:
    string toGoatLatin(string sentence) {
        istringstream iss(sentence);
        int pos = 1;
        unordered_set<char> vowel{'a','e','i','o','u'};
        string res{};
        string temp;
        while(getline(iss, temp, ' ')){
            if(vowel.find(tolower(temp[0])) == vowel.end()){
                char first = temp[0];
                temp.erase(temp.begin());
                temp.push_back(first);
            }
            temp += "ma";
            for(int i = 0; i < pos; ++i){
                temp.push_back('a');
            }
            temp += " ";
            res += temp;
            ++pos;
        }
        res.pop_back();
        return res;
    }
};
