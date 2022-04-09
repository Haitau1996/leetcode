class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        queue<pair<int,int>> curr_que{};
        queue<pair<int,int>> next_que{};
        int m = rooms.size();
        int n = rooms[0].size();
        for(int i = 0; i < m; ++i){
            for(int j = 0; j< n; ++j){
                if(rooms[i][j] == 0){
                    curr_que.push(pair(i,j));
                }
            }
        }
        int dist = 0;
        vector<vector<int>> neighbors{{1,0},{-1,0},{0,1},{0,-1}};
        while(!curr_que.empty()){
            auto front = curr_que.front();
            curr_que.pop();
            for(const auto& elem : neighbors){
                int x = front.first + elem[0];
                int y = front.second + elem[1];
                if(x >=0 && y >= 0 && x< m && y < n && rooms[x][y] == numeric_limits<int>::max()){
                    next_que.push(pair(x,y));
                }
            }
            if(rooms[front.first][front.second] == numeric_limits<int>::max())
                rooms[front.first][front.second] = dist;
            if(curr_que.empty()){
                ++dist;
                swap(curr_que, next_que);
            }
        }
    }
};
