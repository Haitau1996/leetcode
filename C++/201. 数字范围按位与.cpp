class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int leftBits = getHigestBit(left);
        int rightBits = getHigestBit(right);
        if(leftBits < rightBits || leftBits == 0) return 0;
        else{
            int highest = 1 <<(leftBits-1);
            return highest + rangeBitwiseAnd(left - highest, right - highest);
        }
    }
private:
    int getHigestBit(int n){
        int result = 0;
        while(n){
            result = result + 1;
            n>>=1;
        }
        return result;
    }
};