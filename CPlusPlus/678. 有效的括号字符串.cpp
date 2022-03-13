class Solution {
public:
    bool checkValidString(string s) {
        int low = 0;
        int high = 0;
        for(const auto& c : s){
            if(c == '('){
                ++low;
                ++high;
            }else if(c == ')'){
                low = max(0, low-1); 
                --high;
                if(high < 0) return false;
            }
            else{
                low = max(0,low-1);
                ++high;
            }
        }
        return low <= 0;
    }
};