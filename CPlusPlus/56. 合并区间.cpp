class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        auto cmp = [](const vector<int>& first, const vector<int>& second){
            else return first[0] < second[0];
        };
        sort(intervals.begin(), intervals.end(), cmp);
        for(int i = 0; i < intervals.size()-1; i++){
            if(intervals[i][1] < intervals[i+1][0]) continue;
            else{
                intervals[i+1][0] = intervals[i][0];
                intervals[i+1][1] = std::max(intervals[i][1],intervals[i+1][1]);
                intervals[i][0] = -1;
            }
        }
        auto new_end = std::remove_if(intervals.begin(), intervals.end(),[](const vector<int>& elem){
            return elem[0] == -1;
        });
        intervals.erase(new_end, intervals.end());
        return intervals;
    }
};