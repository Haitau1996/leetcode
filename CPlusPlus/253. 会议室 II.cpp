class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        int max= 0;
        sort(intervals.begin(), intervals.end());
        auto cmp = [](vector<int>& first, vector<int>& second){
            return first[1] > second[1];
        };
        std::priority_queue<std::vector<int>, std::vector<std::vector<int>>, decltype(cmp)> pq(cmp);
        for(const auto& elem : intervals){
            while(!pq.empty() && pq.top()[1] <= elem[0]){
                pq.pop();
            }
            pq.push(elem);
            if(pq.size() > max) max = pq.size();
        }
        return max;
    }
};