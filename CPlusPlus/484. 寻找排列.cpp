#include <string>
#include <vector>

using namespace std;
class Solution {
public:
    vector<int> findPermutation(string s)
    {
        vector<int> res {};
        int low = 1;
        int beg = 0;
        int end = 0;
        while (beg < s.size()) {
            while (end < s.size() && s[end] == 'D') {
                ++end;
            }
            for (int i = 0; beg + i < end; ++i) {
                res.push_back(low + (end - beg) - i);
            }
            res.push_back(low);
            beg = end + 1;
            end = beg;
            low = res.size() + 1;
        }
        if (res.size() == s.size())
            res.push_back(low);
        return res;
    }
};
