/*
雨水是从能通过 BFS 走到的最矮边上漏的， 因此我们使用一个优先队列从小到大保存每个边， 然后依次取出最短的点对它上下左右没有检查过的点做广度优先搜索
    case 1: 临近的点值小于pq的头， 那么结果就加上差值， 然后修改该点的值为头的大小
    case 2: 临近点的值大于等于等于 pq 的头， 忽略
两种情况都要将点压入优先队列， 并且标记为已经访问过。 优先队列的比较是使用在 heightMap 中的值实现的， 因此我们需要使用 lambda 表达式传入自定义的比较运算符。
*/
#include <vector>
#include <utility>
#include <queue>

using namespace std;
class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        int m = heightMap.size();
        int n = heightMap[0].size();
        vector<vector<bool>> checked(m, vector<bool>(n,false));
        auto cmp = [&heightMap](pair<int,int>& a, pair<int,int>& b){
            return heightMap[a.first][a.second] > heightMap[b.first][b.second];
        };
        priority_queue<pair<int,int>,vector<pair<int,int>>,decltype(cmp)> mypq(cmp);
        for(int i = 1; i < m-1; ++i){
            mypq.push(pair<int,int>(i,0));
            mypq.push(pair<int,int>(i, n-1));
            checked[i][0] = true;
            checked[i][n-1] = true;
        }
        for(int j = 1; j < n-1; ++j){
            mypq.push(pair<int,int>(0,j));
            mypq.push(pair<int,int>(m-1,j));
            checked[0][j] = true;
            checked[m-1][j] = true;
        }
        vector<pair<int,int>> nexts{{-1,0},{1,0},{0,1},{0,-1}};
        int result = 0;
        while(mypq.size()){
            auto head = mypq.top();
            for(const auto& elem:nexts){
                auto x = elem.first + head.first;
                auto y = elem.second + head.second;
                if(x > 0 && x < m-1 && y > 0 && y < n- 1 && !checked[x][y]){
                    if(heightMap[x][y] < heightMap[head.first][head.second]){
                        result += (heightMap[head.first][head.second] - heightMap[x][y]);
                        heightMap[x][y] = heightMap[head.first][head.second];
                    }
                    mypq.emplace(x,y);
                    checked[x][y] = true;
                }
            }
            mypq.pop();
        }
        return result;
    }  
};
