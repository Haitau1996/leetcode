class Solution {
public:
    int convertInteger(int A, int B) {
        A^=B;
        return countBit(A);
    }
private:
    int countBit(unsigned a){
        if(a == 0) return 0;
        else return 1 + countBit(a &(a-1));
    }
};