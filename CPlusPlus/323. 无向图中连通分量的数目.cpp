class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<bool> visited(n, false);
        unordered_map<int, unordered_set<int>> graph{};
        for(const auto& elem : edges){
            auto& first = elem[0];
            auto& second = elem[1];
            if(graph.find(first) == graph.end())
                graph.emplace(first, unordered_set<int>());
            graph[first].insert(second);
            if(graph.find(second) == graph.end())
                graph.emplace(second, unordered_set<int>());
            graph[second].insert(first);
        }
        int count = 0;
        for(int i = 0; i < n; ++i){
            if(!visited[i]){
                bfs(i, visited, graph);
                ++count;
            }
        }
        return count;
    }
    void bfs(int index, vector<bool>& visited, unordered_map<int, unordered_set<int>>& graph){
        queue<int> todo;
        todo.push(index);
        visited[index] = true;
        while(!todo.empty()){
            auto front = todo.front();
            todo.pop();
            for(const auto & elem : graph[front]){
                if(!visited[elem]){
                    todo.push(elem);
                    visited[elem] = true;
                }
            }
        }
    }
};
