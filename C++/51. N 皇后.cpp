/*
执行用时：4 ms, 在所有 C++ 提交中击败了93.75% 的用户
内存消耗：6.9 MB, 在所有 C++ 提交中击败了96.27% 的用户
这道题目是理解回溯的典型例子， 主要思路如下
* 每次对插入的第 n 个数， 将 i从 0 到 n-1 检查冲突
    * 如果不冲突就插入,否则， i+1
    * 如果哪个地方插入0..n-1都不行，那么就说明这条路死了，将已经插入的最后一个值val弹出， 从 val + 1 开始遍历
    * 如果已经插入了 n 个数， 保存结果， 然后将插入的最后一个值val弹出， 从 val + 1 开始遍历， 它会一直弹出
        * 直到所有的情况都检查完毕， 这时候 n 就是 -1
*/
#include <string>
#include<vector>
using namespace std;
class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res_str{};
        vector<int> res_int{};
        int added = 0;
        int start = 0;
        int i;
        while(added >= 0){
            for(i = start; i < n; ++i){
                if(pass(res_int, i)){
                    res_int.push_back(i);
                    ++added;
                    start = 0;
                    break;
                }
            }
            if(added==n){
                res_str.emplace_back(int2str(res_int,n));
                start = res_int.back() + 1;
                res_int.pop_back();
                --added;
            }
            if(i == n){
                if(added != 0){
                    start = res_int.back() + 1;
                    res_int.pop_back();
                }
                --added;
            }
        }
        return res_str;
    }
private:
    vector<string> int2str(vector<int>& res_int, int n){
        vector<string> result = vector<string>(n, string(n,'.'));
        for(int i = 0; i< n; ++i){
            result[i][res_int[i]] = 'Q';
        }
        return result;
    }
    bool pass(vector<int>&before, int toAdd){
        if(before.empty()) return true;
        for(int i = 0; i < before.size(); ++i){
            if(before[i] == toAdd || abs(before[i]-toAdd) == before.size() - i)
                return false;
        }
        return true;
    }
};