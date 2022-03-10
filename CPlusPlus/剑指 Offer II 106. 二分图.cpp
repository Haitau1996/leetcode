/*
之前用 dfs 实现过一次， 这次用 bfs 实现
需要特别注意两个地方容易引起死循环
1. colors[i] < 0 之后才需要 check 他的 childern ， 因为大于等于 0 已经检查过了
2. 队列记得 pop
*/
class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> colors(graph.size(), -1);
        for(int i = 0; i < graph.size(); ++i){
            if(colors[i] == -1){
                if(!bfs(graph, colors, i, 0)) return false;
            }
        }
        return true;
    }
private: 
    bool bfs(vector<vector<int>>& graph, vector<int>& colors, int index, int color){
        queue<int> current{};
        queue<int> next{};
        current.push(index);
        while(!current.empty()){
            while(!current.empty()){
                auto i = current.front();
                if(colors[i] >= 0 && colors[i]!=color) return false;
                if(colors[i] < 0) {
                    colors[i] = color;
                    for(const auto& elem : graph[i])
                        next.push(elem);
                }
                current.pop();
            }
            color = 1 - color;
            swap(current, next);
        }
        return true;
    }
};