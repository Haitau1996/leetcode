/*
 * 基础实现： 二分查找 + BFS 判定
 * TODO: 使用并查集实现
 */
class Solution {
    using mp = pair<int, int>;
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int left = 0; 
        int right = static_cast<int>(1E6);
        vector<mp> neighbors{{1,0}, {-1,0}, {0,1},{0,-1}};
        auto bfs = [&heights, &neighbors](int mid)->bool{
            int m = heights.size();
            int n = heights[0].size();
            mp tail(m-1,n-1);
            vector<vector<bool>> checked(m, vector<bool>(n,0));
            queue<mp> que{};
            que.emplace(0,0);
            checked[0][0] = true;
            while(!que.empty()){
                auto front = que.front();
                if(front == tail) return true;
                for(const auto& nei: neighbors){
                    int x = nei.first + front.first;
                    int y = nei.second + front.second;
                    if(x>= 0 && x < m && y >= 0 && y <n && !checked[x][y] && abs(heights[x][y] - heights[front.first][front.second])<= mid){
                        que.emplace(x,y);
                        checked[x][y] = true;
                    }
                }
                que.pop();
            }
            return false;
        };
        while(left < right){
            int mid = (left + right) >> 1;
            if(bfs(mid)) right = mid;
            else left = mid + 1;
        }
        return left;
    }
};