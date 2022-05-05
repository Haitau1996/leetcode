// TODO: 核心的功能还没有实现

#include <string>
#include <vector>

using namespace std;
class Solution {
public:
    bool isValid(string code) {
        int low = 1; 
        int high = code.size()-1;
        if(code[0] != '<') return false;
        else{
            while(low < 10 && code[low] != '>'){
                if(code[low] >= 'A' && code[low] <= 'Z') ++low;
                else return false;
            }
            if(code[low] != '>') return false;
            auto tag = code.substr(0, low+1);
            tag.insert(tag.begin()+ 1,'/');
            auto tail = code.substr(code.size()-tag.size(), tag.size());
            if(tag != tail) return false;
            else{
                auto content = code.substr(low+1, code.size() - tag.size()*2 + 1);
                return check_content(content);
            }
        }
        return true;
    }
private:
    bool check_content(string & content){
        return true;
    }
};
