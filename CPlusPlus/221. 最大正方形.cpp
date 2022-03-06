class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int global_max = 0;
        auto dp = vector<vector<int>>(matrix.size(),vector<int>(matrix[0].size(),0));
        for(int i = 0; i < matrix.size(); ++i){
            if(matrix[i][0] == '1') dp[i][0] = 1;
            if(global_max < dp[i][0]) global_max = dp[i][0];
        }
        for(int j = 0; j < matrix[0].size(); ++j){
            if(matrix[0][j] == '1') dp[0][j] = 1;
            if(global_max < dp[0][j]) global_max = dp[0][j];
        }
        for(int i = 1; i < matrix.size(); ++i){
            for(int j = 1; j < matrix[0].size(); ++j){
                if(matrix[i][j] != '0'){
                    int end = dp[i-1][j-1];
                    int start = 0;
                    while(start < end && matrix[i-1-start][j]!= '0' && matrix[i][j-1-start]!='0'){
                        ++start;
                    }
                    dp[i][j] = start+1;
                    if(start+1 > global_max) global_max = start + 1;
                }
            }
        }
        return global_max*global_max;
    }
};