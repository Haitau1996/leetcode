class Solution {
public:
    int addDigits(int num) {
        if(num%9) return num%9;
        else if(num == 0) return 0;
        else return 9;
    }
};