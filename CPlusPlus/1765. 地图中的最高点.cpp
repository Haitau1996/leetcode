#include <vector>
#include <queue>
using namespace std;
class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        queue<vector<int>> current_que{};
        queue<vector<int>> next_que{};
        int m = isWater.size();
        int n = isWater[0].size();
        vector<vector<bool>> checked(m, vector<bool>(n, false));
        for(int i = 0;i < m;++i){
            for(int j = 0; j < n; ++j){
                if(isWater[i][j]){
                    current_que.push(vector<int>{i,j});
                    isWater[i][j] = 0;
                    checked[i][j] = true;
                }
            }
        }
        int height = 1;
        vector<vector<int>> nexts{{-1,0},{1,0},{0,-1},{0,1}};
        while(!current_que.empty()){
            while(!current_que.empty()){
                auto front = current_que.front();
                current_que.pop();
                for(const auto& elem : nexts){
                    int x = elem[0] + front[0];
                    int y = elem[1] + front[1];
                    if(x >= 0 && y >= 0 && x < m && y < n && !checked[x][y]){
                        isWater[x][y] = height;
                        checked[x][y] = true;
                        next_que.push(vector<int>{x,y});
                    }
                }
            }
            swap(current_que, next_que);
            height++;
        }
        return isWater;
    }
};
