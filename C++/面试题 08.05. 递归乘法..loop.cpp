class Solution {
public:
    int multiply(int A, int B) {
        return A > B ? bit_multiply(A,B) : bit_multiply(B,A);
    }
private:
    int bit_multiply(int A, int B){
        int bit=0;
        int result = 0;
        while(B){
            result += (B&0x1)? (A<<bit) : 0;
            ++bit;
            B>>=1;
        }
        return result;
    }
};