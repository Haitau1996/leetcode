#include <string>
#include <vector>

using namespace std;
class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right)
    {
        int curr = left;
        vector<int> res {};
        while (curr <= right) {
            if (valid(curr))
                res.push_back(curr);
            ++curr;
        }
        return res;
    }
    bool valid(int curr)
    {
        string s = to_string(curr);
        for (const auto& c : s) {
            if (c == '0')
                return false;
            if (curr % (c - '0') != 0)
                return false;
        }
        return true;
    }
};
