class Solution {
public:
    string convertToBase7(int num) {
        if(num < 0 ) return "-" + convertToBase7(-num);
        else if(num < 7){
            string result{};
            result.push_back(num+'0');
            return result;
        }else{
            return convertToBase7(num/7) + convertToBase7(num%7);
        }
    }
};