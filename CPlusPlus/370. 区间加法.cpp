// 基本做法， 将阶梯写成一个数组，排序后挨个处理阶梯间的元素
// 进阶做法： 先将前后之差保存在数组中， 然后做前缀和
#include <algorithm>
#include <vector>

using namespace std;
class BasicSolution {
public:
    vector<int> getModifiedArray(int length, vector<vector<int>>& updates)
    {
        vector<vector<int>> stairs;
        for (const auto& elem : updates) {
            auto start = elem[0];
            auto end = elem[1] + 1;
            stairs.emplace_back(vector<int> { start, elem[2] });
            stairs.emplace_back(vector<int> { end, -elem[2] });
        }
        sort(stairs.begin(), stairs.end());
        int curr_i = 0;
        int curr_val = 0;
        int curr_s = 0;
        vector<int> res(length, 0);
        while (curr_i < res.size() && curr_s < stairs.size()) {
            while (curr_i < res.size() && curr_i < stairs[curr_s][0]) {
                res[curr_i++] = curr_val;
            }
            curr_val += stairs[curr_s++][1];
        }
        return res;
    }
};
class BetterSolution {
public:
    vector<int> getModifiedArray(int length, vector<vector<int>>& updates) {
        vector<int> res(length,0);
        for(const auto& elem:updates){
            res[elem[0]] += elem[2];
            if(elem[1]+1 < length) res[elem[1]+1]-=elem[2];
        }
        for(int i = 1; i < length; ++i){
            res[i] += res[i-1];
        }
        return res;
    }
};
