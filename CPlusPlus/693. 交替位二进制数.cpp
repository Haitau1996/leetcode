class Solution {
public:
    bool hasAlternatingBits(int n) {
        int status = n&0x1;
        n >>= 1;
        while(n){
            if(n&0x1 && status) return false;
            else if(n&0x1 || status){
                status = n&0x1;
                n >>= 1;
            }else{
                return false;
            }
        }
        return true;
    }
};
