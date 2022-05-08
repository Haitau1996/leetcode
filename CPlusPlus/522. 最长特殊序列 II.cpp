#include <algorithm>
#include <string>
#include <vector>

using namespace std;
class Solution {
public:
    int findLUSlength(vector<string>& strs)
    {
        auto cmp = [](const string& a, const string& b) {
            if (a.size() != b.size()) {
                return a.size() > b.size();
            } else
                return a > b;
        };
        sort(strs.begin(), strs.end(), cmp);
        int low = 0;
        int high = 0;
        while (low < strs.size()) {
            while (high < strs.size() && strs[low] == strs[high]) {
                ++high;
            }
            if (high - low == 1) {
                bool status = true;
                for (int i = 0; i < low; ++i) {
                    if (is_child(strs[i], strs[low])) {
                        status = false;
                        break;
                    }
                }
                if (status)
                    return strs[low].size();
            }
            low = high;
        }
        return -1;
    }

private:
    bool is_child(string& s, string& c)
    {
        int curA = 0;
        int curC = 0;
        while (curA < s.size() && curC < c.size()) {
            if (s[curA] == c[curC]) {
                ++curA;
                ++curC;
            } else
                ++curA;
        }
        return curC == c.size();
    }
};
