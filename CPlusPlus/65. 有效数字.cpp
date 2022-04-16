#include<string>

using namespace std;

class Solution {
public:
    bool isNumber(string s) {
        int sz = s.size();
        int cursor = 0;
        bool has_integer = false;
        bool evalid = true;
        if(cursor == sz ) return false;

        cursor = check_sign_bit(s, cursor);
        if(cursor == sz ) return false;
        
        int new_cursor = ingore_integer(s, cursor);
        if(new_cursor > cursor){
            has_integer = true;
            if(new_cursor == sz) return true;
            cursor = new_cursor;
        }
        cursor = check_points(s, cursor);
        if(cursor == sz && has_integer) return true;
        if(cursor == sz && !has_integer) return false;

        new_cursor = ingore_integer(s, cursor);
        if(new_cursor > cursor){
            has_integer = true;
            if(new_cursor == sz) return true;
        }
        cursor = new_cursor;

        new_cursor = check_sci(s, cursor);
        if(new_cursor > cursor){
            evalid = false;
            if(new_cursor == sz) return false;
        }
        cursor = new_cursor;

        if(!evalid) cursor= check_sign_bit(s, cursor);
        new_cursor = ingore_integer(s, cursor);
        if(new_cursor > cursor){
            evalid = true;
        }
        cursor = new_cursor;
        if(cursor == s.size() && has_integer && evalid) return true;
        return false;
    }
private:
    int check_sign_bit(string& s, int pos){
        if(pos< s.size() &&(s[pos] == '+' || s[pos] == '-'))
            return pos + 1;
        else return pos;
    }
    int ingore_integer(string& s, int pos){
        while(pos < s.size() && isdigit(s[pos])){
            ++pos;
        }
        return pos;
    }
    int check_points(string&s, int pos){
        if(pos < s.size() && s[pos] == '.'){
            return pos + 1;
        }
        else return pos;
    }
    int check_sci(string& s, int pos){
        if(pos <s.size() && (s[pos] == 'e' || s[pos] == 'E')){
            return pos+1;
        }
        return pos;
    }
};
