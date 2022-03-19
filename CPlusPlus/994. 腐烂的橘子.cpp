/*
 没别的东西， 就是两个队列做 BFS
*/
#include<vector>
#include<queue>
using namespace std;
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<vector<int>> current_bad_orange{};
        int good_orange_count{0};
        queue<vector<int>> next_bad_orange{};
        int m = grid.size();
        int n = grid[0].size();
        int minites_of_time{0};
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if(grid[i][j] == 1) ++good_orange_count;
                else if(grid[i][j] == 2) current_bad_orange.push(vector<int>{i,j});
            }
        }
        vector<vector<int>> next{{-1,0},{1,0},{0,-1},{0,1}};
        while(!current_bad_orange.empty()){
            while(!current_bad_orange.empty()){
                auto front = current_bad_orange.front();
                current_bad_orange.pop();
                for(const auto& elem : next){
                    int x = front[0] + elem[0];
                    int y = front[1] + elem[1];
                    if(x >= 0 && y >= 0 && x < m && y < n && grid[x][y] == 1){
                        grid[x][y] = 2;
                        good_orange_count--;
                        next_bad_orange.push(vector<int>{x,y});
                    }
                }
            }
            if(!next_bad_orange.empty()){
                swap(current_bad_orange, next_bad_orange);
                minites_of_time++;
            }
        }
        if(good_orange_count) return -1;
        else return minites_of_time;
    }
};
