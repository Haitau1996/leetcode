// 简单的二分查找， 一定要记得处理加法越界的情况
class Solution {
public:
    int guessNumber(int n) {
        unsigned low = 1;
        unsigned high = n;
        while(low < high){
            unsigned mid = (low + high)/2;
            if(guess(mid) == 0) return mid;
            else if(guess(mid) == 1) low = mid + 1;
            else high = mid - 1;
        }
        return low;
    }
};
