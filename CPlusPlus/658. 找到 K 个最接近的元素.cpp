#include <vector>
#include <deque>

using namespace std;
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        deque<int> res{};
        auto i = binary_search(arr, x);
        int left; 
        int right;
        if(i!= -1 && arr[i] >= x){
            left = i-1;
            right = i;
        }else{
            left = i;
            right = i+1;
        }
        while(res.size() < k){
            if(right == arr.size() || (left >= 0 && x - arr[left] <= arr[right] - x)){
                res.push_front(arr[left]);
                --left;
            }else{
                res.push_back(arr[right]);
                ++right;
            }
        }
        return vector<int>(res.begin(), res.end());
    }
private:
    int binary_search(vector<int>& arr, int k){
        int low = 0;
        int high = arr.size()-1;
        while(low < high){
            auto mid = (low + high )>>1;
            if(arr[mid] == k) return mid;
            else if(arr[mid] > k){
                high = mid -1;
            } else{
                low = mid + 1;
            }
        }
        return low;
    }
};
