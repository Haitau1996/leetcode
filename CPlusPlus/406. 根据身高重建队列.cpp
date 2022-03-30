#include<vector>
#include<queue>
#include<map>
using namespace std;
class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        priority_queue<vector<int>,vector<vector<int>>, std::greater<vector<int>>> pq;
        multimap<int, int> to_handle;
        multimap<int, int> memo{};
        vector<vector<int>> result;
        for(const auto & elem : people){
            if(elem[1] == 0){
                pq.push(elem);
            }
            else{
                to_handle.emplace(elem[0],elem[1]);
            }
            memo.emplace(elem[0],elem[1]);
        }
        while(!pq.empty()){
            auto front = pq.top();
            int key = front[0];
            auto range = memo.equal_range(key);
            auto start = range.first;
            int val = start->second;
            for(auto  beg = range.first; beg != range.second; ++beg){
                if(beg->second < val){
                    val = beg->second;
                    start = beg;
                }
            }
            memo.erase(start);
            pq.pop();
            result.push_back(vector<int>{key,val});
            auto bound = to_handle.upper_bound(key);
            for(auto iter = to_handle.begin(); iter != bound; ++iter){
                iter->second = iter->second - 1;
                if(iter ->second == 0) {
                    pq.push(vector<int>{iter->first,iter->second});
                }
            }
        }
        return result;
    }
};
