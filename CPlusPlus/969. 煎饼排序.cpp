// 贪心算法： 每次将当下最大的值放到最后， 然后缩小范围
// 标准库中有 reverse 函数， 接收一个左闭右开区间， 不用自己写
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> pancakeSort(vector<int>& arr)
    {
        int max_rank = arr.size();
        vector<int> res;
        while (max_rank > 0) {
            int max_index = distance(arr.begin(), max_element(arr.begin(), arr.begin() + max_rank));
            if (max_index == max_rank - 1) {
                --max_rank;
            } else {
                if (max_index != 0) {
                    res.push_back(max_index + 1);
                    reverse(arr.begin(), arr.begin() + max_index + 1);
                }
                res.push_back(max_rank);
                reverse(arr.begin(), arr.begin() + max_rank);
                --max_rank;
            }
        }
        return res;
    }
};
