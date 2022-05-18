// 有点类似于水塘抽样
#include <vector>

using namespace std;
class Solution {
public:
    Solution(vector<int>& nums)
    {
        val = nums;
    }

    vector<int> reset()
    {
        return val;
    }

    vector<int> shuffle()
    {
        vector<int> res {};
        for (int i = 0; i < val.size(); ++i) {
            res.push_back(val[i]);
            int pos = rand() % res.size();
            swap(res[i], res[pos]);
        }
        return res;
    }

private:
    vector<int> val;
};
