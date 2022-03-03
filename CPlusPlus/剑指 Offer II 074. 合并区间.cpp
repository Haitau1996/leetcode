/*
执行用时：16 ms, 在所有 C++ 提交中击败了85.69% 的用户
内存消耗：13.6 MB, 在所有 C++ 提交中击败了99.59% 的用户
* 需要考虑特殊的输入，如包含 [0,0] 的情况
* numeric_limits 萃取值的时候记得加上括号
* erase 接收的是两个迭代器【beg,end), 而 beg 可以从 remove_if 中获得
*/
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        std::sort(  intervals.begin(), 
                    intervals.end(),
                    [](vector<int>&a ,vector<int>&b){ 
                       return a[0] < b[0];
                    });
        for(int i =0; i < intervals.size()-1; ++i){
            if(intervals[i][1] >= intervals[i+1][0]){
                intervals[i+1][1] = std::max(intervals[i][1],intervals[i+1][1]);
                intervals[i+1][0] = intervals[i][0];
                intervals[i][0] = std::numeric_limits<int>::min();
                intervals[i][1] = std::numeric_limits<int>::min();
            }
        }
        intervals.erase(std::remove_if (intervals.begin(),
                                        intervals.end(),
                                        [](vector<int>& buffer){
                                            return  buffer[0] == std::numeric_limits<int>::min() 
                                                    && buffer[1]==std::numeric_limits<int>::min();
                                        }),
                        intervals.end());
        return intervals;
    }
};