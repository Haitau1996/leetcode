/*
* 需要注意的是， 如果 实参为 const&， 那么函数的行参也必须带上 const 声明保证不会修改该参数
*/
class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        for(const auto& elem : words){
            if(isPalindrome(elem)) return elem;
        }
        return string("");
    }
private:
    bool isPalindrome(const string& input)const {
        size_t low = 0;
        size_t high = input.size() - 1;
        while(low < high){
            if(input[low] == input[high]){
                ++low;
                --high;
            }
            else return false;
        }
        return true;
    }
};