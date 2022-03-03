/*
执行用时：4 ms, 在所有 C++ 提交中击败了92.06% 的用户
内存消耗：8.2 MB, 在所有 C++ 提交中击败了70.53% 的用户
*/
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        for(int i = triangle.size()-2; i >=0; i--){
            for(size_t j = 0; j< triangle[i].size(); ++j){
                triangle[i][j] = triangle[i][j] + std::min(triangle[i+1][j] , triangle[i+1][j+1]);
            }
        }
        return triangle[0][0];
    }
};