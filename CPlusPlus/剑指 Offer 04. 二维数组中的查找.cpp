// 二分查找， 记得区域的划分， 在相等的时候返回 true, 在大于和小于 target 的时候都可以划出两个不想交的区域分别查找
// 还有就是要记得考虑数组为空的情况
#include <vector>
using std::vector;
class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target)
    {
        int m = matrix.size();
        if (m == 0)
            return false;
        int n = matrix[0].size();
        if (n == 0)
            return false;
        return find_in_range(matrix, 0, 0, m - 1, n - 1, target);
    }

private:
    bool find_in_range(vector<vector<int>>& mat, int m_s, int n_s, int m_e, int n_e, int target)
    {
        if (m_s > m_e || n_s > n_e)
            return false;
        int m_mid = (m_s + m_e) / 2;
        int n_mid = (n_s + n_e) / 2;
        if (mat[m_mid][n_mid] == target) {
            return true;
        } else if (mat[m_mid][n_mid] > target) {
            return find_in_range(mat, m_s, n_s, m_e, n_mid - 1, target) || find_in_range(mat, m_s, n_mid, m_mid - 1, n_e, target);
        } else
            return find_in_range(mat, m_s, n_mid + 1, m_e, n_e, target) || find_in_range(mat, m_mid + 1, n_s, m_e, n_mid, target);
    }
};
