class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        dfs(graph,0,graph.size()-1);
        return result;
    }
private:
    vector<vector<int>> result{};
    vector<int> selected{0};
    void dfs(vector<vector<int>>& graph, int source, int dest){
        if(source == dest){
            result.push_back(selected);
            return;
        }
        else if(graph[source].size() == 0){
            return;
        }
        else{
            for(auto elem: graph[source]){
                selected.push_back(elem);
                dfs(graph,elem,dest);
                selected.pop_back();
            }
        }
    }
};