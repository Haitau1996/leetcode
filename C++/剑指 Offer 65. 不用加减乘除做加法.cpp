/*
* 注意负数可能会溢出
*/
class Solution {
public:
    int add(int a, int b) {
        int sum;
        int carry;
        do{
            sum = a ^ b;
            carry = (int)((unsigned)(a & b)<<1);
            a = sum;
            b = carry;
        }while(carry);
        return sum;
    }
};