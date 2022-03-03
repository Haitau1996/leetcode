/*
执行用时：0 ms, 在所有 C++ 提交中击败了100.00% 的用户
内存消耗：6 MB, 在所有 C++ 提交中击败了41.90% 的用户
*/
class Solution {
public:
    bool isStrobogrammatic(string num) {
        return helper(num,0,num.size()-1);
    }
private:
    bool helper(string& num, int low, int high){
        if(low > high)
            return true;
        if(low == high ){
            if (num[low] == '1'||num[low] == '8'||num[low] == '0')
                return true;
            else  
                return false;
        }
        if(num[low] == '1'||num[low] =='8' ||num[low] == '0')
            return num[high] == num[low] &&
                   helper(num, ++low, --high);
        if(num[low] == '6')
            return num[high] == '9' &&
                   helper(num, ++low, --high);
        if(num[low] == '9')
            return num[high] == '6' &&
                   helper(num, ++low, --high);
        else return false;
    }
};