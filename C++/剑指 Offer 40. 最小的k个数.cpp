class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        if(arr.size() <= k) return arr;
        int low = 0;
        int high = arr.size() - 1;
        int mid = partition(arr, low, high);
        while(mid != k){
            if(mid > k){
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
            mid = partition(arr, low, high);
        }
        return vector<int>(arr.begin(), arr.begin()+k);
    }
private:
    int partition(vector<int>& arr, int low, int high){
        if(low == high) return low;
        int pos = low + rand()%(high - low);
        swap(arr[low],arr[pos]);
        int pa = arr[low];
        while(low < high){
            while(low < high && arr[high]>= pa){
                --high;
            }
            if(low < high) swap(arr[low],arr[high]);
            while(low < high && arr[low] <= pa){
                ++low;
            }
            if(low <high) swap(arr[low],arr[high]);
        }
        arr[low] = pa;
        return low;
    }
};