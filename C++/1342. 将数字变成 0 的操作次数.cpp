class Solution {
public:
    int numberOfSteps(int num) {
        int result{};
        while(num){
            if((num & 0x1) && num!=1) ++result;
            ++result;
            num>>=1;
        }
        return result;
    }
};