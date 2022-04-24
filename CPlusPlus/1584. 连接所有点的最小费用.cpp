// 实现 Prime 算法

#include <vector>
#include <queue>

using namespace std;
class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int size = points.size();
        vector<vector<int>> matrix(size, vector<int>(size, numeric_limits<int>::max()));
        for(int i = 0; i < size; ++i){
            for(int j = i+1; j < size; ++j){
                matrix[i][j] = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                matrix[j][i] = matrix[i][j];
            }
        }
        vector<bool> marked(size, false);
        auto cmp = [&matrix](const vector<int>& p, const vector<int>& q){
            return matrix[p[0]][p[1]] > matrix[q[0]][q[1]];
        };
        priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> pq(cmp);
        marked[0] = true;
        int marked_count = 1;
        int res{};
        for(int i = 1; i < size; ++i){
            pq.push(vector<int>{0,i});
        }
        while(marked_count < size){
            auto top = pq.top();
            pq.pop();
            if(marked[top[0]] && marked[top[1]]) continue;
            res += matrix[top[0]][top[1]];
            int next{0};
            if(marked[top[0]]) next = top[1];
            else next = top[0]; 
            marked[next] = true;
            ++marked_count;
            for(int i = 0; i < size; ++i){
                if(!marked[i]){
                    pq.push(vector<int>{next,i});
                }
            }
        }
        return res;
    }
};
