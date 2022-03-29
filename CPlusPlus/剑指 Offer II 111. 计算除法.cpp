#include<set>
#include<map>
#include<vector>
#include<string>

using namespace std;
class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        construct_graph(equations, values);
        vector<double> result;
        for(const auto& elem : queries){
            if(graph.find(elem[0]) == graph.end() || graph.find(elem[1]) == graph.end())
                result.push_back(-1);
            else {
                set<string> visited;
                result.push_back(dfs(elem[0],elem[1],visited));
            }
        }
        return result;
    }
private:
    map<string,map<string, double>> graph;
    void construct_graph(vector<vector<string>>& equations, vector<double>& values){
        for(int i = 0; i < values.size(); ++i){
            auto first = equations[i][0];
            auto second = equations[i][1];
            if(graph.find(first) == graph.end()){
                graph.insert(pair(first, map<string, double>()));
            }
                graph[first].insert({second,values[i]});
            if(graph.find(second) == graph.end()){
                graph.insert(pair(second, map<string, double>()));
            }
                graph[second].insert({first,1.0/values[i]});
        }
    }
    double dfs(string src, string target, set<string> visited){
        if(src == target) return 1.0;
        visited.insert(src);
        for(auto elem : graph[src]){
            auto next = elem.first;
            if(visited.find(next) == visited.end()){
                auto next_val = dfs(next, target, visited);
                if(next_val > 0){
                    return elem.second * next_val;
                }
            }
        }
        visited.erase(src);
        return -1.0;
    }
};
