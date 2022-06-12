// 前缀和 + 二分查找
// 遇到矩形面积的问题， 第一时间时间想到用前缀和求面积降低时间复杂度。
// 而结果在 [0, min(m, n)] 之间， 我们可以使用二分查找找到最大的边长
#include <vector>
using namespace std;
class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold)
    {
        int m = mat.size();
        int n = mat[0].size();
        for (int j = 1; j < mat[0].size(); ++j) {
            mat[0][j] += mat[0][j - 1];
        }
        for (int i = 1; i < mat.size(); ++i) {
            int sum = 0;
            for (int j = 0; j < mat[0].size(); ++j) {
                mat[i][j] = mat[i][j] + mat[i - 1][j] + sum;
                sum = mat[i][j] - mat[i - 1][j];
            }
        }
        int low = 0;
        int high = min(m, n);
        while (low < high) {
            int mid = (low + high + 1) >> 1;
            if (valid(mat, mid, threshold)) {
                low = mid;
            } else {
                high = mid - 1;
            }
        }
        return low;
    }

private:
    bool valid(vector<vector<int>>& mat, int len, int threshold)
    {
        for (int i = len - 1; i < mat.size(); ++i) {
            for (int j = len - 1; j < mat[0].size(); ++j) {
                int total = mat[i][j];
                int left = j < len ? 0 : mat[i][j - len];
                int up = i < len ? 0 : mat[i - len][j];
                int up_left = i < len || j < len ? 0 : mat[i - len][j - len];
                if (total - left - up + up_left <= threshold)
                    return true;
            }
        }
        return false;
    }
};
