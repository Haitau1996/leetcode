/*
做法 1: 暴力递归， 对每个节点做 dfs, 求出以它为节点的树深度
Error: 超出时间限制， 65 / 70 个通过测试用例
做法 2: 取出度最小的边做广度优先搜索， 类似于拓扑排序
*/
#include <vector>
#include <queue>
#include <limits>
#include <unordered_map>
#include <unordered_set>
using namespace std;
class BruteForceSolution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<vector<int>> link_repr(n, vector<int>());
        for(const auto& elem : edges){
            int node1 = elem[0];
            int node2 = elem[1];
            link_repr[node1].push_back(node2);
            link_repr[node2].push_back(node1);
        }
        int height = numeric_limits<int>::max();
        for(int i = 0; i < n; ++i){
            int current_height = get_deepth(i,link_repr, n);
            if(current_height == height){
                result.push_back(i);
            }else if(current_height < height){
                height = current_height;
                result.clear();
                result.push_back(i);
            }
        }
        return result;
    }
private:
    vector<int> result;
    int get_deepth(int current, vector<vector<int>>& link_repr, int n){
        vector<bool> visited(n, false);
        int deepth = 1;
        queue<int> cur_que{};
        queue<int> next_que{};
        cur_que.push(current);
        visited[current] = true;
        while(!cur_que.empty()){
            while(!cur_que.empty()){
                auto front = cur_que.front();
                cur_que.pop();
                for(const auto& elem : link_repr[front]){
                    if(!visited[elem]){
                        next_que.push(elem);
                        visited[elem] = true;
                    }
                }
            }
            swap(cur_que,next_que);
            ++deepth;
        }
        return deepth;
    }
};
class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n == 1){
            if(edges.size()== 0) return vector<int>{0};
            else return vector<int>();
        }
        vector<int> edge_count(n, 0);
        unordered_map<int, unordered_set<int>> graph;
        for(const auto& elem : edges){
            auto& first = elem[0];
            auto& second = elem[1];
            if(graph.find(first) == graph.end())
                graph.emplace(first, unordered_set<int>());
            graph[first].insert(second);
            if(graph.find(second) == graph.end())
                graph.emplace(second, unordered_set<int>());
            graph[second].insert(first);
            ++edge_count[first];
            ++edge_count[second];
        }
        queue<int> curr_que;
        queue<int> next_que;
        int handled{};
        for(int i = 0; i < n; ++i){
            if(edge_count[i] == 1){
                curr_que.push(i);
                handled++;
            }
        }
        vector<int> result{};
        while(!curr_que.empty()){
            result.clear();
            while(!curr_que.empty()){
                auto front = curr_que.front();
                curr_que.pop();
                result.push_back(front);
                for(const auto& elem : graph[front]){
                    --edge_count[elem];
                    if(edge_count[elem] == 1){
                        next_que.push(elem);
                        ++handled;
                    }
                }
            }
            swap(curr_que, next_que);
        }
        return result;
    }
};
