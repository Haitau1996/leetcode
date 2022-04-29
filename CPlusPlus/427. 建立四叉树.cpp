/*
 * 没有什么别的技巧， 就是按照题目要求做深度优先搜索， 定义一个函数检查范围内的值是否相同
case 1 : 相同， 递归的 base case, 返回一个叶子节点
case 2 : 不同， 划分区域， 对不同的区域做 DFS
 */

class Solution {
public:
    Node* construct(vector<vector<int>>& grid)
    {
        int end = grid.size() - 1;
        return construct_in_range(grid, 0, 0, end, end);
    }

private:
    Node* construct_in_range(vector<vector<int>>& grid, int start_m, int start_n, int end_m, int end_n)
    {
        Node* res = new Node();
        if (all_the_same(grid, start_m, start_n, end_m, end_n)) {
            res->isLeaf = true;
            res->val = grid[start_m][start_n];
        } else {
            int sz = (end_m - start_m + 1) >> 1;
            res->isLeaf = false;
            res->topLeft = construct_in_range(grid, start_m, start_n, start_m + sz - 1, start_n + sz - 1);
            res->topRight = construct_in_range(grid, start_m, start_n + sz, start_m + sz - 1, end_n);
            res->bottomLeft = construct_in_range(grid, start_m + sz, start_n, end_m, start_n + sz - 1);
            res->bottomRight = construct_in_range(grid, start_m + sz, start_n + sz, end_m, end_n);
        }
        return res;
    }
    bool all_the_same(vector<vector<int>>& grid, int start_m, int start_n, int end_m, int end_n)
    {
        for (int i = start_m; i <= end_m; ++i) {
            for (int j = start_n; j <= end_n; ++j) {
                if (grid[i][j] != grid[start_m][start_n])
                    return false;
            }
        }
        return true;
    }
};
