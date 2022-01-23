/*
执行用时：0 ms, 在所有 C++ 提交中击败了100.00% 的用户
内存消耗：6.1 MB, 在所有 C++ 提交中击败了79.16% 的用户
*/
class Solution {
public:
    int strToInt(string str) {
        int beg = findBegin(str);
        if(beg == -1) return 0;
        bool neg = false;
        if(str[beg] == '-'){
            neg = true;
            ++beg;
        }
        else if(str[beg] == '+') ++beg;
        while(str[beg] == '0') ++beg;
        int end = findEnd(str,beg);
        unsigned result = toIntCore(str, beg, end);
        if(result > numeric_limits<int>::max()){
            return neg? INT_MIN : INT_MAX;
        }
        else return neg? -(int)result:(int)result;
    }
private:
    int findBegin(string& str){
        for(int i = 0; i < str.size(); ){
            if(str[i] == ' ') ++i;
            else if(str[i] == '-'|| str[i] == '+' || (str[i] >= '0' && str[i]<='9')) return i;
            else return -1;
        }
        return -1;
    }
    int findEnd(string& str, int beg){
        for(int i = beg; i < str.size(); ++i){
            if(str[i]>'9' || str[i] < '0') return i;
        }
        return str.size();
    }
    unsigned toIntCore(string& str, int beg, int end){
        if(beg == end) return 0;
        if(end - beg > 10) return std::numeric_limits<unsigned int>::max();
        else if(end -beg == 10 && str[beg] > '2') return std::numeric_limits<unsigned int>::max();
        unsigned result = 0;
        int bits = 0;
        for(int i = end-1; i >= beg; --i){
            result += powsOfTens(bits) * (int)(str[i] - '0');
            ++bits;
        }
        return result; 
    }
    unsigned powsOfTens(int in){
        unsigned result = 1;
        for(int i = 0; i < in; ++i) result *=10;
        return result;
    }
};