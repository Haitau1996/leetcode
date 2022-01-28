/* 
* 非常傻逼的题目， 各路边界 case 需要测定得非常清楚
1. 如果 a 为 numeric_limits<int>::min() 且 b 为 -1， int 装不下， 返回 numeric_limits<int>::max() 
2. 所有的 取负数操作都用位运算
3. b 可能最高位为 1， 无法左移动
*/
class Solution {
public:
    int divide(int a, int b) {        
        if(a == numeric_limits<int>::min() && b == -1 ){
            return numeric_limits<int>::max();
        }
        if(a >= 0 && b > 0) return divideCore(a,b);
        else if(a >= 0 && b < 0) return 0 - divideCore(a,~((unsigned)b)+1);
        else if(a < 0 && b > 0) return 0 - divideCore((~(unsigned)a) + 1 ,b);
        return divideCore((~(unsigned)a) + 1,~((unsigned)b)+1);
    }
private:
    unsigned divideCore(unsigned a, unsigned b){
        if(b > a) return 0;
        if(a == b) return 1;
        unsigned left_bits = 1;
        while(a > (b<<left_bits)){
            ++left_bits;
        }
        return (1<<(left_bits-1)) + divideCore(a-(b<<(left_bits-1)),b);
    }
};