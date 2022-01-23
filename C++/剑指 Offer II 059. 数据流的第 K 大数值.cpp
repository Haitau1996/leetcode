/*
执行用时：32 ms, 在所有 C++ 提交中击败了66.75% 的用户
内存消耗：19.3 MB, 在所有 C++ 提交中击败了66.63% 的用户
* 最小堆需要传入参数 greater<T>()
* c++ 默认是最大堆， 默认参数是 less<T>()
*/
class KthLargest {
public:
    KthLargest(int k, vector<int>& nums) {
        assert(k <= nums.size() + 1);
        if(k == nums.size()+1){
            nums.push_back(std::numeric_limits<int>::min());
        }
        heap = vector<int>(nums.begin(), nums.begin()+k);
        std::make_heap(heap.begin(), heap.end(), greater<int>());
        for(int i = k; i< nums.size(); ++i){
            add(nums[i]);
        }
    }
    
    int add(int val) {
        if(val > heap[0]) {
            std::pop_heap(heap.begin(), heap.end(), greater<int>());
            heap.pop_back();
            heap.push_back(val);
            std::push_heap(heap.begin(), heap.end(), greater<int>());
            
        }
        return heap[0];
    }
private:
    vector<int> heap;
};