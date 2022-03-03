/*
执行用时：24 ms, 在所有 C++ 提交中击败了82.70% 的用户
内存消耗：17.4 MB, 在所有 C++ 提交中击败了99.00% 的用户
* 需要考虑特殊的输入
* partition 的实现非常常用
*/
class Solution {
public:
    vector<int> smallestK(vector<int>& arr, int k) {
        assert(arr.size()>=k);
        if(k == arr.size()) return arr;
        int low = 0;
        int high = arr.size()-1;
        int index = partition(arr, low, high);
        while(index != k){
            if(index > k) high = index-1;
            else low = index+1;
            index = partition(arr, low, high);
        }
        return vector<int>(arr.begin(), arr.begin()+k);
    }
private:
    int partition(vector<int>& arr, int low, int high){
        if(low == high) return low;
        int pivot = arr[low];
        while(low < high){
            while(low < high && arr[high]>=pivot){
                --high;
            }
            arr[low] = arr[high];
            while(low < high && arr[low] <= pivot){
                ++low;
            }
            arr[high] = arr[low];
        }
        arr[low] = pivot;
        return low;
    }
};