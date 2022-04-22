/*
 * 使用多源广度优先搜索， 效率有点低。
 * Solution2 使用动态规划（前缀和）实现， 效率更高
 */
#include <vector>
#include <unordered_set>

using namespace std;
class Solution {
public:
    string pushDominoes(string dominoes) {
        unordered_set<int> curr_left;
        unordered_set<int> next_left;
        unordered_set<int> curr_right;
        unordered_set<int> next_right;
        int sz = dominoes.size();
        vector<bool> checked(sz, false);
        for(int i = 0; i < sz; ++i){
            if(dominoes[i] == 'R') {
                curr_right.insert(i);
                checked[i] = true;
            }else if(dominoes[i] == 'L'){
                curr_left.insert(i);
                checked[i] = true;
            }
        }
        while(!curr_left.empty() || !curr_right.empty()){
            vector<bool> current(sz, false);
            for(const auto& elem : curr_left){
                if(curr_right.find(elem) != curr_right.end()){
                    curr_right.erase(elem);
                }else{
                    dominoes[elem] = 'L';
                }
                int temp = elem - 1;
                if(temp >= 0 && temp < sz && !checked[temp]){
                    next_left.insert(temp);
                    checked[temp] = true;
                    current[temp] = true;
                }
            }
            swap(curr_left, next_left);
            next_left.clear();
            for(const auto& elem : curr_right){
                dominoes[elem] = 'R';
                int temp = elem + 1;
                if(temp >= 0 && temp < sz &&(!checked[temp] || current[temp])){
                    next_right.insert(temp);
                    checked[temp] = true;
                }
            }
            swap(curr_right, next_right);
            next_right.clear();
        }
        return dominoes;
    }
};
// 解法2： 使用前缀和， 记录它距离左右牌的最近距离。
class Solution2 {
public:
    string pushDominoes(string dominoes) {
        int sz = dominoes.size();
        vector<int> leftDist(sz, sz);
        vector<int> rightDist(sz, sz);
        for(int i = 0; i < sz; ++i){
            if(dominoes[i] == 'R'){
                rightDist[i] = 0;
            }else if(i > 0 && rightDist[i-1]!=sz && dominoes[i] != 'L'){
                rightDist[i] = rightDist[i-1] + 1;
            }
            if(dominoes[sz-1-i] == 'L'){
                leftDist[sz-1-i] = 0;
            }else if(i > 0 && leftDist[sz - i]!= sz && dominoes[sz-1-i]!='R'){
                leftDist[sz-1-i] = leftDist[sz-i] + 1;
            }
        }
        for(int i = 0; i < sz; ++i){
            if(dominoes[i] == '.'){
                if(leftDist[i] < rightDist[i]){
                    dominoes[i] = 'L';
                }else if(leftDist[i] > rightDist[i]){
                    dominoes[i] = 'R';
                }
            }
        }
        return dominoes;
    }
};
