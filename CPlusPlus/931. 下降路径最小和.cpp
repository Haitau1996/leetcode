class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        for(int i = 1; i < m; ++i){
            for(int j = 0; j < n; ++j){
                int first = (j == 0 ? numeric_limits<int>::max() : matrix[i-1][j-1]);
                int second = matrix[i-1][j];
                int third = (j == n-1? numeric_limits<int>::max(): matrix[i-1][j+1]);
                matrix[i][j] += min({first,second,third});
            }
        }
        return *min_element(matrix.back().begin(),matrix.back().end());
    }
};
