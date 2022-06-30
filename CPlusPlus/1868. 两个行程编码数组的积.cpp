/*
 * 双指针： 记录当下的长度， 如果相等， 则都向后挪一位， 否则挪动短的并且修改长的值
 * 涉及到数组的操作， 一定要注意下标, 因为一旦出现输入错误， 十分难以调试
 */
#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> findRLEArray(vector<vector<int>>& encoded1, vector<vector<int>>& encoded2) {
        vector<vector<int>> res{};
        for(int cur1 = 0, cur2 = 0; cur1 < encoded1.size() && cur2 < encoded2.size(); ){
            vector<int>& v1 = encoded1[cur1];
            vector<int>& v2 = encoded2[cur2];
            if(v1[1] == v2[1]){
                res.push_back(vector<int>{v1[0]*v2[0], v1[1]});
                ++cur1;
                ++cur2;
            }else if(v1[1] > v2[1]){
                res.push_back(vector<int>{v1[0]*v2[0], v2[1]});
                v1[1]-=v2[1];
                ++cur2;
            }else{
                res.push_back(vector<int>{v1[0]*v2[0], v1[1]});
                v2[1]-=v1[1];
                ++cur1;
            }
        }
        for(int i = 0; i < res.size()-1; ++i){
            if(res[i+1][0] == res[i][0]){
                res[i+1][1] += res[i][1];
                res[i][0] = 0;
                res[i][1] = 0;
            }
        }
        auto iter = remove(res.begin(), res.end(), vector<int>{0,0});
        res.erase(iter, res.end());
        return res;
    }
};
