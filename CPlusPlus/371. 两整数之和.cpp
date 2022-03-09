class Solution {
public:
    int getSum(int a, int b) {
        unsigned temp = a ^ b;
        unsigned carry = a & b;
        while(carry){
            b = (carry << 1);
            a = temp;
            temp = a ^ b;
            carry = a & b;
        }
        return temp;
    }
};