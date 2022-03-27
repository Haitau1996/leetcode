class Solution {
public:
    int firstBadVersion(int n) {
        unsigned low = 1;
        unsigned high = n;
        while(low < high){
            unsigned mid = (low + high)/2;
            if(isBadVersion(mid) && (mid == 1 || !isBadVersion(mid-1)))
                return mid;
            else if(isBadVersion(mid)){
                high = mid - 1;
            }else{
                low = mid+1;
            }
        }
        return low;
    }
};
