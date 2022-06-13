// 典型的二分查找问题， 类似于猴子吃香蕉
#include <vector>
#include <algorithm>

using namespace std;
class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        if(bloomDay.size()/k < m) return -1;
        int low = *min_element(bloomDay.begin(), bloomDay.end());
        int high = *max_element(bloomDay.begin(), bloomDay.end());
        while(low < high){
            int mid = (low + high) >> 1;
            if(valid_day(bloomDay, mid, m, k)){
                high = mid;
            }else low = mid + 1;
        }
        return low;
    }
private:
    bool valid_day(vector<int>& days, int mid, int m, int k){
        size_t cursor = 0;
        int sum = 0;
        int prefix = 0;
        while(cursor < days.size()){
            if(days[cursor] <= mid){
                ++prefix;
            }else{
                prefix = 0;
            }
            if(prefix==k){
                ++sum;
                if(sum >= m) return true;
                prefix = 0;
            }
            ++cursor;
        }
        return false;
    }
};
