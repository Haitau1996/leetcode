/*
熟悉了一个 C++ 中的 bitset 用法
回溯求解时候一个重要的去重做法就是先将待选择的元素排序，然后回溯的时候检查 i 和 i-1 处是否相等， 如果相等就直接跳过不做递归求解
*/
#include <vector>
#include <string>
#include <algorithm>
#include <bitset>
using namespace std;
class Solution {
public:
    vector<string> generatePalindromes(string s) {
        std::bitset<26> bs{};
        string odds{};
        for(const auto& elem : s){
            if(bs[elem-'a']){
                odds.push_back(elem);
            }
            bs.flip(elem-'a');
        }
        if(bs.count() > 1) return vector<string>();
        for(int i = 0; i < bs.size() ; ++i){
            if(bs[i]) even.push_back(i+'a');
        }
        sort(odds.begin(), odds.end());
        dfs(odds);
        return result;
    }
private:
    string even{};
    string selected{};
    vector<string> result{};
    void dfs(string odds){
        if(odds.size() == 0){
            if(selected.size()!=0 || even.size() != 0){
                string selected_copy(selected);
                reverse(selected_copy.begin(), selected_copy.end());
                result.push_back(selected + even + selected_copy);
            }
            return;
        }
        for(int i = 0; i < odds.size(); ++i){
            string new_odds(odds);
            if(i == 0 || (i >0 && odds[i]!=odds[i-1])){
                selected.push_back(odds[i]);
                new_odds.erase(new_odds.begin()+i);
                dfs(new_odds);
                selected.pop_back();
            }
        }
    }
};
