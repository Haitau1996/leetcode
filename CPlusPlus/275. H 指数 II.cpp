/*
 * 典型的二分查找， 就是要特别注意有没有包含 下标指向的那篇文章
 */
#include <vector>
using namespace std;
class Solution {
public:
    int hIndex(vector<int>& citations) {
        int low = 0; 
        int high = citations.size()-1;
        int size = citations.size();
        while(low < high){
            int mid = (low + high)/2;
            if(size - mid >= citations[mid] && size-mid-1 < citations[mid+1]){
                if(citations[mid] < size-mid){
                    return size-mid-1;
                }else{
                    return size-mid;
                }
            }                
            else if(size-mid >= citations[mid]){
                low = mid + 1;
            }else{
                high = mid -1;
            }
        }
        if(citations[low] < size-low){
                    return size-low-1;
        }else{
                    return size-low;
        }
    }
};
