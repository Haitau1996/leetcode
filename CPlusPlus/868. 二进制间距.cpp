// 做法1： 简单位运算
class Solution {
public:
    int binaryGap(int n) {
        int bit_pos = 0;
        int last_pos = 0;
        bool status = false;
        int cmp = 0x1;
        int res{0};
        while(cmp < n){
            if(cmp&n){
                if(status && bit_pos-last_pos > res){
                    res = bit_pos - last_pos;
                }
                last_pos = bit_pos;
                status= true;
            }
            ++bit_pos;
            cmp <<= 1;
        }
        return res;
    }
};
