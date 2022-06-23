/*
 * 并查集： 如果是树那么就只有一个连通分量， 并且边的数目为 n-1
 */
#include <vector>
using std::vector;
class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges)
    {
        if (edges.size() != n - 1)
            return false;
        u = vector<int>(n, 0);
        for (int i = 0; i < n; ++i)
            u[i] = i;
        count = n;
        for (const auto& e : edges) {
            int p = e[0];
            int q = e[1];
            if (uni(p, q))
                return false;
        }
        return count == 1;
    }

private:
    vector<int> u;
    int count;
    int find(int p)
    {
        while (p != u[p]) {
            p = u[p];
        }
        return p;
    }
    bool uni(int p, int q)
    {
        int pRoot = find(p);
        int qRoot = find(q);
        if (pRoot == qRoot)
            return true;
        u[pRoot] = qRoot;
        --count;
        return false;
    }
};
