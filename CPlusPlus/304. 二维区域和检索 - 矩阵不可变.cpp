#include<vector>
using namespace std;
class NumMatrix {
public:
    NumMatrix(vector<vector<int>>& mat) {
        int m = static_cast<int>(mat.size());
        int n = static_cast<int>(mat[0].size());
        sum_mat = mat;
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
    }
    
    int sumRegion(int i_beg, int j_beg, int i_end, int j_end) {
        int area1 = sum_mat[i_end][j_end];
        int area2 = ((i_beg == 0 || j_beg == 0)? 0 : sum_mat[i_beg-1][j_beg-1]);
        int diff1 = ((i_beg == 0) ? 0 : sum_mat[i_beg-1][j_end]);
        int diff2 = ((j_beg == 0) ? 0 : sum_mat[i_end][j_beg-1]);
        return area1 + area2 - diff1 - diff2;
    }
private:
    vector<vector<int>> sum_mat;
};
