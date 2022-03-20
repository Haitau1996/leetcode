/*
做法 1: 暴力递归， 对每个节点做 dfs, 求出以它为节点的树深度
Error: 超出时间限制， 65 / 70 个通过测试用例
*/
#include <vector>
#include <queue>
#include <limits>

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
