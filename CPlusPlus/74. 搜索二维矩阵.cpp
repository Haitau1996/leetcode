/*
 * 第一个直接想法是两次二分： 先二分查找所在行， 再二分查找
 * 更好一些的做法是直接分块查找，只需要保证不同的块不重合
 */
#include <vector>

using namespace std;
class Solution { // 两次二分
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target)
    {
        if (target < matrix[0][0] || target > matrix[matrix.size() - 1][matrix[0].size() - 1])
            return false;
        auto line = getLine(matrix, 0, matrix.size() - 1, target);
        return inLine(matrix[line], 0, matrix[line].size() - 1, target);
    }

private:
    int getLine(vector<vector<int>>& matrix, int low, int high, int target)
    {
        if (low >= high)
            return low;
        int mid = (low + high) / 2;
        int mid_beg = matrix[mid][0];
        int mid_end = matrix[mid][matrix[mid].size() - 1];
        if (target < mid_beg)
            return getLine(matrix, low, mid - 1, target);
        else if (target > mid_end)
            return getLine(matrix, mid + 1, high, target);
        return mid;
    }
    bool inLine(vector<int>& line, int low, int high, int target)
    {
        if (target < line[low] || target > line[high])
            return false;
        if (low >= high) {
            if (line[low] == target)
                return true;
            else
                return false;
        }
        int mid = (low + high) / 2;
        if (line[mid] > target)
            return inLine(line, low, mid - 1, target);
        else if (line[mid] < target)
            return inLine(line, mid + 1, high, target);
        else
            return true;
    }
};
class BetterSolution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target)
    {
        int m = matrix.size();
        int n = matrix[0].size();
        return search_in_range(matrix, target, 0, 0, m - 1, n - 1);
    }

private:
    bool search_in_range(vector<vector<int>>& matrix, int target, int rows, int cols, int rowe, int cole)
    {
        if (rows > rowe || cols > cole)
            return false;
        int rowm = (rows + rowe) >> 1;
        int colm = (cols + cole) >> 1;
        if (matrix[rowm][colm] == target)
            return true;
        if (matrix[rowm][colm] > target) {
            return search_in_range(matrix, target, rows, cols, rowm, colm - 1) || search_in_range(matrix, target, rows, colm, rowm - 1, cole);
        } else {
            return search_in_range(matrix, target, rowm, colm + 1, rowe, cole) || search_in_range(matrix, target, rowm + 1, cols, rowe, colm);
        }
    }
};
