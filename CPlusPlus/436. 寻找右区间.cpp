// 应该可以二分， 但是想想直接用 map, 红黑树应该和二分差不大多
#include <map>
#include <vector>

using namespace std;
class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals)
    {
        map<vector<int>, int> hash {};
        for (int i = 0; i < intervals.size(); ++i) {
            hash.emplace(intervals[i], i);
        }
        vector<int> res;
        for (int i = 0; i < intervals.size(); ++i) {
            auto iter = hash.find(intervals[i]);
            while (iter != hash.end() && iter->first[0] < intervals[i][1]) {
                ++iter;
            }
            if (iter == hash.end()) {
                res.push_back(-1);
            } else {
                res.push_back(iter->second);
            }
        }
        return res;
    }
};
