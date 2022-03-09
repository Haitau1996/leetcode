/*
比较少写 bfs 的题目， 有很大的优化空间， 基本的思路是这样的：
1. 使用两个队列 current, next， 先将 0 周围的非 0 点压入待处理的队列 current 中
2. 当待处理的队列不空，依次将其中点的值更新为 flag, 并将它周围未处理的点压入到 next 中准备在下一轮循环中处理
3. 待处理的队列空了之后， 将它和 swap 交换， 重复步骤 2
*/
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        vector<vector<bool>> checked(mat.size(),vector<bool>(mat[0].size(), false));
        vector<vector<int>> result(mat.size(),vector<int>(mat[0].size(), numeric_limits<int>::max()));
        int flag{1};
        queue<vector<int>> current{};
        queue<vector<int>> next{};
        vector<vector<int>> neighbors{{1,0},{-1,0},{0,1},{0,-1}};
        for(int i = 0; i < mat.size(); ++i){
            for(int j = 0;  j< mat[0].size(); ++j){
                if(!checked[i][j] && mat[i][j] == 0){
                    result[i][j] = 0;
                    checked[i][j] = true;
                    for(const auto& elem : neighbors){
                        int new_i = i + elem[0];
                        int new_j = j + elem[1];
                        if(new_i>= 0 && new_i < mat.size() && new_j >= 0 && new_j < mat[0].size() && !checked[new_i][new_j] && mat[new_i][new_j]){
                            current.push(vector<int>{new_i,new_j});
                            checked[new_i][new_j] = true;
                        }
                    }
                }
            }
        }
        while(!current.empty()){
            while(!current.empty()){
                int i = current.front()[0];
                int j = current.front()[1];
                result[i][j] = flag;
                for(const auto& elem : neighbors){
                    int new_i = i + elem[0];
                    int new_j = j + elem[1];
                    if(new_i>= 0 && new_i < mat.size() && new_j >= 0 && new_j < mat[0].size() && !checked[new_i][new_j] && mat[new_i][new_j]){
                        next.push(vector<int>{new_i,new_j});
                        checked[new_i][new_j] = true;
                    }
                }
                current.pop();
            }
            swap(current,next);
            flag = flag + 1;
        }
        return result;
    }
};