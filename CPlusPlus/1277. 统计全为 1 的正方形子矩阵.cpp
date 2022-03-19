/*
更新 matrix 中的值， 使得 matrix[i][j] 为以 点(i,j) 为右下角的最大正方形边长， 如果 matrix[i][j] 为 1， 那么画个图就能看出新值就是 [i-1][j-1],[i-1][j],[i][j-1] 三个的最小值加一。 
这相当于一个带备忘录的动态规划， 求解 [i][j] 的时候需要的三个值都是已知的。
*/
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int m = static_cast<int>(matrix.size());
        int n = static_cast<int>(matrix[0].size());
        int result = 0;
        for(int i = 0; i < m;++i){
            for(int j = 0; j < n; ++j){
                if(matrix[i][j] != 0){
                    if(i >0 && j > 0) matrix[i][j] = min({matrix[i-1][j-1], matrix[i][j-1],matrix[i-1][j]}) + 1;
                    result += matrix[i][j];
                }
            }
        }
        return result;
    }
};
