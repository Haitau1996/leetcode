/*
执行用时：4 ms, 在所有 C++ 提交中击败了21.84% 的用户
内存消耗：6.3 MB, 在所有 C++ 提交中击败了74.74% 的用户
* 没什么好说的， 动态规划基本题目
*/
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result{};
        for(int i = 1; i <= numRows; ++i){
            if(i == 1) result.emplace_back(vector<int>{1});
            else{
                vector<int> temp{1};
                for(int j=1; j <i-1; ++j){
                    temp.push_back(result.back()[j-1]+result.back()[j]);
                }
                temp.push_back(1);
                result.push_back(std::move(temp));
            }
        }
        return result;
    }
};