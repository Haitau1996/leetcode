// 矩阵中分块二分查找: 注意终止条件是 end < start, 别写反了

#include <vector>

using namespace std;
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target)
    {
        if (matrix.size() == 0 || matrix[0].size() == 0)
            return false;
        return search_in_range(matrix, target, 0, 0, matrix.size() - 1, matrix[0].size() - 1);
    }

private:
    bool search_in_range(vector<vector<int>>& matrix, int target, int rows, int cols, int rowe, int cole)
    {
        if (rowe < rows || cole < cols)
            return false;
        int rowm = (rows + rowe) >> 1;
        int colm = (cols + cole) >> 1;
        if (matrix[rowm][colm] == target)
            return true;
        else if (matrix[rowm][colm] > target)
            return search_in_range(matrix, target, rows, cols, rowm - 1, cole) || search_in_range(matrix, target, rowm, cols, rowe, colm - 1);
        else
            return search_in_range(matrix, target, rowm + 1, cols, rowe, cole) || search_in_range(matrix, target, rows, colm + 1, rowm, cole);
    }
};
