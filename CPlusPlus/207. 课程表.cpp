/*
  这相当于是拓扑排序的第一步， 先检查一个图有没有环
*/
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        auto graph = vector<vector<int>>(numCourses,vector<int>());
        for(const auto& prerequisite:prerequisites){
            graph[prerequisite[0]].push_back(prerequisite[1]);
        }
        vector<bool> visited(numCourses, false);
        for(int i = 0; i < numCourses; ++i){
            if(bfs(graph, visited,i, i)) return false;
        }
        return true;
    }
private:
    bool bfs(vector<vector<int>>& graph, vector<bool> visited, int start, int target){
        queue<int> to_check{};
        for(const auto elem: graph[start]){
            to_check.push(elem);
            visited[elem] = true;
        }
        while(!to_check.empty()){
            int top = to_check.front();
            if(top == start) return true;
            to_check.pop();
            for(const auto elem: graph[top]){
                if(!visited[elem]){
                    visited[elem] = true;
                    to_check.push(elem);
                }
            }
        }
        return false;
    }
};