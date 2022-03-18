/*
典型的动态规划题目， 使用一个 vector of vectors sum_mat,
其中 sum_mat[i][j]存放从 [0][0] 到 [i][j]的矩形区域的和，然后从[a,b] 到 [c,d] 的面积就是
sum_mat[c][d] + sum_mat[a-1][b-1] - sum_mat[a-1][d] - sum_mat[c][b-1]
*/
#include <algorithm>
#include <vector>

using namespace std;
class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int m = static_cast<int>(mat.size());
        int n = static_cast<int>(mat[0].size());
        auto sum_mat = mat;
        for(int i = 0; i < m; ++i){
            for(int j = 1; j < n; ++j){
                sum_mat[i][j] += sum_mat[i][j-1];
            }
        }
        for(int i = 1; i < m; ++i){
            for(int j = 0; j < n; ++j){
                sum_mat[i][j] += sum_mat[i-1][j];
            }
        }
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                int i_beg = max(0, i-k);
                int j_beg = max(0, j-k);
                int i_end = min(i+k, m-1);
                int j_end = min(j+k, n-1);
                int area1 = sum_mat[i_end][j_end];
                int area2 = ((i_beg == 0 || j_beg == 0)? 0 : sum_mat[i_beg-1][j_beg-1]);
                int diff1 = ((i_beg == 0) ? 0 : sum_mat[i_beg-1][j_end]);
                int diff2 = ((j_beg == 0) ? 0 : sum_mat[i_end][j_beg-1]);
                mat[i][j] = area1 + area2 - diff1 - diff2;
            }
        }
        return mat;
    }
};
