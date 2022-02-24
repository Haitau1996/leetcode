class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        for(int i = 1; i < triangle.size(); ++i){
            for(int j = 0; j <= i; ++j){
                if(j == 0) triangle[i][j] = triangle[i-1][j] + triangle[i][j];
                else if(j == i) triangle[i][j] = triangle[i-1][j-1] + triangle[i][j];
                else triangle[i][j] = min(triangle[i-1][j-1],triangle[i-1][j]) + triangle[i][j];
            }
        }
        return *min_element(triangle.back().begin(), triangle.back().end());
    }
};