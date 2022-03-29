#include<vector>
#include<queue>
#include<utility>
#include<unordered_map>

using namespace std;
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        queue<int> curr_que{};
        queue<int> next_que{};
        unordered_multimap<int, int> next_course{};
        vector<int> result{};
        vector<int> preCourseCount(numCourses, 0);
        for(const auto& elem : prerequisites){
            preCourseCount[elem[0]] = preCourseCount[elem[0]]+1;
            next_course.insert(pair(elem[1],elem[0]));
        }
        for(int i = 0; i < numCourses; ++i){
            if(preCourseCount[i] == 0) {
                curr_que.push(i);
                result.push_back(i);
            }
        }
        while(!curr_que.empty()){
            auto front = curr_que.front();
            curr_que.pop();
            auto range = next_course.equal_range(front);
            for(auto iter = range.first; iter != range.second; ++iter){
                auto prev_course = iter->second;
                preCourseCount[prev_course]--;
                if(preCourseCount[prev_course] == 0){
                    curr_que.push(prev_course);
                    result.push_back(prev_course);
                }
            }
        }
        if(result.size() == numCourses) return result;
        return vector<int>();
    }
};
