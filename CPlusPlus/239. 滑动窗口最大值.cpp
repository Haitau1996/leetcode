/*
* 第一次使用 priority_queue, 之前都是调用 push_heap,pop_heap 的算法
*/
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        auto cmp = [&nums](int a, int b){
            return nums[a] < nums[b];
        };
        priority_queue<int, vector<int>,decltype(cmp)> pq(cmp);
        for(int i = 0; i < k-1; ++i){
            pq.push(i);
        }
        vector<int> result{};
        for(int i = k-1; i < nums.size(); ++i){
            pq.push(i);
            while(pq.top()<= (i-k)){
                pq.pop();
            }
            result.push_back(nums[pq.top()]);
        }
        return result;
    }
};