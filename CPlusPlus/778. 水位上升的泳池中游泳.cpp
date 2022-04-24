// 暴力解法， 超出时间限制
// TODO: 使用查并集做优化 
#include<vector>
#include<queue>
#include<set>
using namespace std;
class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        m = grid.size(); 
        n = grid[0].size();
        vector<vector<bool>> graph(m, vector<bool>(n, false));
        auto cmp = [&grid](const vector<int>& a, const vector<int>& b){
            return grid[a[0]][a[1]] > grid[b[0]][b[1]];
        };
        priority_queue<vector<int>,vector<vector<int>>, decltype(cmp)> pq(cmp);
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                pq.push(vector<int>{i,j});
            }
        }
        while(!pq.empty()){
            const auto& top = pq.top();
            graph[top[0]][top[1]] = true;
            if(bfs(graph)) return grid[top[0]][top[1]];
            pq.pop();
        }
        return 0;
    }
private:
    int m;
    int n;
    bool bfs(vector<vector<bool>>& graph){
        queue<vector<int>> que{};
        set<vector<int>> visited{};
        vector<int> dest{m-1, n-1};
        vector<vector<int>> neighbors{{-1,0},{1,0},{0,1},{0,-1}};
        if(graph[0][0]) {
            que.push(vector<int>{0,0});
            visited.emplace(vector<int>{0,0});
        }
        while(!que.empty()){
            auto front = que.front();
            if(front == dest) return true;
            que.pop();
            for(const auto& elem : neighbors){
                vector<int> temp{front[0]+elem[0],front[1]+elem[1]};
                if(temp[0] >= 0 && temp[0] < m && temp[1] >=0 && temp[1] < n && graph[temp[0]][temp[1]] && visited.find(temp) == visited.end()){
                    que.push(temp);
                    visited.emplace(temp);
                }
            }
        }
        return false;
    }
};
