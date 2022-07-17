/*
 * 做法 1： 并查集
 * 做法 2： 广度优先搜索/深度优先搜索
 */
#include <vector>

using namespace std;
class Union_Find_Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections)
    {
        int edge_cnt = connections.size();
        if (edge_cnt < n - 1)
            return -1;
        idx = vector<int>(n, 0);
        for (int i = 0; i < n; ++i)
            idx[i] = i;
        set_cnt = n;
        rank = vector<int>(n, 1);
        for (const auto& c : connections) {
            unite(c[0], c[1]);
        }
        return set_cnt - 1;
    }

private:
    vector<int> idx;
    vector<int> rank;
    int set_cnt;
    int find(int p)
    {
        while (p != idx[p])
            p = idx[p];
        return p;
    }
    void unite(int p, int q)
    {
        int proot = find(p);
        int qroot = find(q);
        if (proot == qroot)
            return;
        if (rank[proot] > rank[qroot]) {
            idx[qroot] = proot;
        } else {
            idx[qroot] = proot;
            if (rank[proot] == rank[qroot]) {
                ++rank[proot];
            }
        }
        --set_cnt;
    }
};

#include <queue>
#include <unordered_map>
#include <unordered_set>
class BFS_Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections)
    {
        if (connections.size() < n - 1)
            return -1;
        for (const auto& c : connections) {
            con[c[1]].push_back(c[0]);
            con[c[0]].push_back(c[1]);
        }
        vector<bool> visited(n, false);
        int cnt {};
        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                bfs(i, visited);
                ++cnt;
            }
        }
        return cnt - 1;
    }

private:
    unordered_map<int, vector<int>> con;
    void bfs(int i, vector<bool>& visited)
    {
        queue<int> next;
        visited[i] = true;
        next.push(i);
        while (!next.empty()) {
            auto fnt = next.front();
            for (const auto nei : con[fnt]) {
                if (!visited[nei]) {
                    visited[nei] = true;
                    next.push(nei);
                }
            }
            next.pop();
        }
    }
};
