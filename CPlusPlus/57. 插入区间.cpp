class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        auto iter = lower_bound(intervals.begin(), intervals.end(), newInterval);
        auto index = std::distance(intervals.begin(),iter);
        intervals.insert(iter, newInterval);
        for(int beg = index+1; beg < intervals.size(); ++beg){
            if(intervals[beg][0] > newInterval[1]) break;
            else{
                intervals[beg][0] = numeric_limits<int>::min();
                newInterval[1] = max(newInterval[1],intervals[beg][1]);
                intervals[index][1] = max(newInterval[1],intervals[beg][1]);
                intervals[beg][1] = numeric_limits<int>::min();
            }
        }
        for(int beg = index -1; beg >= 0; --beg){
            if(intervals[beg][1] < newInterval[0]){
                break;
            }
            else{
                if(intervals[beg][1] > intervals[index][1]){
                    intervals[index][1] = intervals[beg][1];
                }
                intervals[beg][1] = numeric_limits<int>::min();
                newInterval[0] = min(newInterval[0],intervals[beg][0]);
                intervals[index][0] = min(newInterval[0],intervals[beg][0]);
                intervals[beg][0] = numeric_limits<int>::min();
            }
        }
        vector<int> temp(2, numeric_limits<int>::min());
        auto del_iter = std::remove(intervals.begin(),intervals.end(),temp);
        intervals.erase(del_iter, intervals.end());
        return intervals;
    }
};