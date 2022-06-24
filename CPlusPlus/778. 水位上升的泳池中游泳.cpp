// 二分 + BFS， O(2n^2log(n))
// TODO: 使用并查集做实现 
#include<vector>
#include<queue>
#include<set>
using namespace std;

class Solution {
    using mp = pair<int, int>;
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        int left = 0;
        int right = n*n;
        tail = mp(n-1, n-1);
        while(left < right){
            int mid = (left+right) >> 1;
            if(bfs(grid, mid)) right = mid;
            else left = mid + 1;
        }
        return left;
    }
private:
    mp tail;
    bool bfs(vector<vector<int>>& grid, int curr){
        int n = grid.size();
        vector<vector<bool>> checked(n, vector<bool>(n, false));
        queue<mp> que{};
        if(grid[0][0] <= curr){
            que.emplace(0,0);
            checked[0][0] = true;
        }
        vector<vector<int>> neighbors{{1,0},{-1,0},{0,1},{0,-1}};
        while(!que.empty()){
            auto front = que.front();
            if(front == tail) return true;
            for(const auto& nei:neighbors){
                int x = front.first + nei[0];
                int y = front.second + nei[1];
                if(x >= 0 && x < n && y >= 0 && y < n && !checked[x][y] && grid[x][y] <= curr){
                    que.emplace(x,y);
                    checked[x][y] = true;
                }
            }
            que.pop();
        }
        return false;
    }
};