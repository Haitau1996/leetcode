/*
BFS 
*/
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int m = image.size();
        int n = image[0].size();
        vector<vector<bool>> modefied(m, vector<bool>(n,0));
        const int BASE_COLOR = image[sr][sc];
        queue<vector<int>> to_check{};
        vector<vector<int>> neighbor_distance{{-1,0},{1,0},{0,1},{0,-1}};
        to_check.push(vector<int>{sr,sc});
        image[sr][sc] = newColor;
        modefied[sr][sc] = true;
        while(!to_check.empty()){
            auto front = to_check.front();
            to_check.pop();
            for(const auto& diff :neighbor_distance){
                int x = front[0]+diff[0];
                int y = front[1]+diff[1];
                if(x >=0 && x < m && y >= 0 && y < n && !modefied[x][y] && image[x][y] == BASE_COLOR){
                    modefied[x][y] = true;
                    image[x][y] = newColor;
                    to_check.push(vector<int>{x,y});
                }
            }
        }
        return image;
    }
};