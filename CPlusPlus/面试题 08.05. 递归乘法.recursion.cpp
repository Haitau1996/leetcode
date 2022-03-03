class Solution {
public:
    int multiply(int A, int B) {
        return A > B ? bit_multiply(A,B) : bit_multiply(B,A);
    }
private:
    int bit_multiply(int A, int B){
        if(B == 0) return 0;
        else if(B == 1) return A;
        else return bit_multiply(A, B&0x1) + bit_multiply(A<<1,B>>1);
    }
};