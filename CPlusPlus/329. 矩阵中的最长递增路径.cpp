/*
  矩阵可以看成是一个无环的图， 暴力 dfs 就能解决
*/
#include<vector>
using namespace std;
class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        m = matrix.size();
        n = matrix[0].size();
        vector<vector<int>> buffer(m, vector<int>(n, -1));
        int result = 0;
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                buffer[i][j] = dfs(matrix,buffer,i,j);
                if(buffer[i][j] > result) result = buffer[i][j];
            }
        }
        return result;
    }
private:
    int m;
    int n;
    int dfs(vector<vector<int>>& matrix, vector<vector<int>>& buffer, int i,int j){
        if(buffer[i][j] != -1) return buffer[i][j];
        else{
            vector<vector<int>> nexts{{-1,0},{1,0},{0,1},{0,-1}};
            int local_max = 0;
            for(const auto& next: nexts){
                int new_i = next[0] + i;
                int new_j = next[1] + j;
                if(new_i >= 0 && new_j >= 0 && new_i < m && new_j < n && matrix[new_i][new_j] > matrix[i][j]){
                    int temp = dfs(matrix, buffer, new_i, new_j);
                    if(temp > local_max) local_max = temp;
                }
            }
            buffer[i][j] = local_max + 1;
            return local_max+1;
        }
    }
};
