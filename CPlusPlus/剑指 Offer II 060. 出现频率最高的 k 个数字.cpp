/*
执行用时：12 ms, 在所有 C++ 提交中击败了85.30% 的用户
内存消耗：13.4 MB, 在所有 C++ 提交中击败了39.61% 的用户
* 需要注意， push_heap/make_heap/pop_heap 在 cmp 不为默认的时候都要传入 cmp
*/
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        std::unordered_map<int,int> nums_count{};
        for(auto&elem :nums){
            if(nums_count.find(elem) == nums_count.end()){
                nums_count[elem] = 0;
            }
            ++nums_count[elem];
        }
        vector<std::pair<int,int>> min_heap{};
        auto cmp = [](const auto& p, const auto &q ){
                        return p.second > q.second;
                    };
        for(const auto &elem : nums_count){
            if(min_heap.size() < k-1) min_heap.push_back(elem);
            else if(min_heap.size() == k-1){
                min_heap.push_back(elem);
                std::make_heap(min_heap.begin(),min_heap.end(),cmp);
            }
            else{
                if(elem.second > min_heap[0].second){
                    std::pop_heap(min_heap.begin(), min_heap.end(),cmp);
                    min_heap.pop_back();
                    min_heap.push_back(elem);
                    std::push_heap(min_heap.begin(), min_heap.end(),cmp);
                }
            }
        }
        vector<int> result;
        for(const auto& elem : min_heap){
            result.push_back(elem.first);
        }
        return result;
    }
};